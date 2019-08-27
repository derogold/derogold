// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2018, The TurtleCoin Developers
//
// Please see the included LICENSE file for more information.

#pragma once

#include <config/CryptoNoteConfig.h>

#include <CryptoNoteCore/CachedTransaction.h>
#include <CryptoNoteCore/TransactionApi.h>

#include <Wallet/WalletErrors.h>

namespace CryptoNote
{
  class Mixins
  {
    public:

      /* Returns {minMixin, maxMixin, defaultMixin} */
      static std::tuple<uint64_t, uint64_t, uint64_t> getMixinAllowableRange(const uint64_t height)
      {
        uint64_t minMixin = CryptoNote::parameters::MINIMUM_MIXIN_V0;
        uint64_t maxMixin = CryptoNote::parameters::MAXIMUM_MIXIN_V0;
        uint64_t defaultMixin = CryptoNote::parameters::DEFAULT_MIXIN_V0;

        return {minMixin, maxMixin, defaultMixin};
      }

      /* This method is used by WalletService to determine if the mixin amount is correct
         for the current block height */
      static std::tuple<bool, std::string, std::error_code> validate(const uint64_t mixin, const uint64_t height)
      {
        auto [minMixin, maxMixin, defaultMixin] = getMixinAllowableRange(height);

        std::stringstream str;

        if (mixin < minMixin)
        {
          str << "Mixin of " << mixin << " under minimum mixin threshold of " << minMixin;
          return {false, str.str(), make_error_code(CryptoNote::error::MIXIN_BELOW_THRESHOLD)};
        }
        else if (mixin > maxMixin)
        {
          str << "Mixin of " << mixin << " above maximum mixin threshold of " << maxMixin;
          return {false, str.str(), make_error_code(CryptoNote::error::MIXIN_ABOVE_THRESHOLD)};
        }

        return {true, std::string(), std::error_code()};
      }

      /* This method is commonly used by the node to determine if the transactions in the vector have
         the correct mixin (anonymity) as defined by the current rules */
      static std::tuple<bool, std::string> validate(std::vector<CachedTransaction> transactions, uint64_t height)
      {
        auto [minMixin, maxMixin, defaultMixin] = getMixinAllowableRange(height);

        for (const auto& transaction : transactions)
        {
            auto [success, error] = validate(transaction, minMixin, maxMixin);

            if (!success)
            {
                return {false, error};
            }
        }

        return {true, std::string()};
      }

      /* This method is commonly used by the node to determine if the transaction has
         the correct mixin (anonymity) as defined by the current rules */
      static std::tuple<bool, std::string> validate(const CachedTransaction& transaction, uint64_t minMixin, uint64_t maxMixin)
      {
        uint64_t ringSize = 1;

        const auto tx = createTransaction(transaction.getTransaction());

        for (size_t i = 0; i < tx->getInputCount(); ++i) {
          if (tx->getInputType(i) != TransactionTypes::InputType::Key) {
            continue;
          }

          KeyInput input;
          tx->getInput(i, input);
          const uint64_t currentRingSize = input.outputIndexes.size();
          if (currentRingSize > ringSize) {
              ringSize = currentRingSize;
          }
        }

        /* Ring size = mixin + 1 - your transaction plus the others you mix with */
        const uint64_t mixin = ringSize - 1;

        std::stringstream str;

        if (mixin > maxMixin) {
          str << "Transaction " << transaction.getTransactionHash()
            << " is not valid. Reason: transaction mixin is too large (" << mixin
            << "). Maximum mixin allowed is " << maxMixin;

          return {false, str.str()};
        } else if (mixin < minMixin) {
          str << "Transaction " << transaction.getTransactionHash()
            << " is not valid. Reason: transaction mixin is too small (" << mixin
            << "). Minimum mixin allowed is " << minMixin;

          return {false, str.str()};
        }

        return {true, std::string()};
      }
  };
}
