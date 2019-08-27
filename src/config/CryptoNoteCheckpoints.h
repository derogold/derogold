// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstddef>
#include <initializer_list>

namespace CryptoNote {
struct CheckpointData {
  uint32_t index;
  const char* blockId;
};

const std::initializer_list<CheckpointData> CHECKPOINTS = {
    {1,         "fbf224231d84591c157dc04f512ccd4151e75478f447176446c67d99f80b54b5"},
    {5000,      "acb63abe6239f97b663c2273816f310af7af8ce6bc2e3c38e08f52b45a5b4744"},
    {10000,     "90d9a950a83979c10edff20215e843adcad1928ab260da28470c95eb2705a330"},
    {15000,     "6a607037a7601fa0ee2d3bfc84137b0a7114587ca17fb116f10ced60ff93cda4"},
    {20000,     "55cd847160754eebf2737c9b391c78cf6e595b761b91b122c229eff3338c37bb"},
    {25000,     "13c46f534f4b314ce3976c38b30bb41b0c9e5fd633e004af4e12704734ea145c"},
    {30000,     "64694538e1887fde57032cc5037971c2e11e7d28329be23dc40d9d7142590a09"},
    {35000,     "54575e2a4634f983cfbbe06ccfbbf06ed8f8469ee5a4e081d7e5f034bb17e37d"},
    {40000,     "4230a7978ea4f09b6232d0a53eac70fa6842784bd8b9acc4e8151c1f762e74cd"},
    {45000,     "4e4cd9ae5ff58a6e57d78ac80bd093648d81eed9c821faf946807d5ca19155f9"},
    {50000,     "bd62ab2e668e5b3345878f83e03f1db284f0ada79a56bfe02d87209a0b4f5ddd"},
    {55000,     "af76a3c5e1522c2338d2b8593424e1e02e0195729410784a8a987f7d380d19d1"},
    {60000,     "f22971a0fa7331df2d0060d7976a03f24e1711f54c9cb1093534a54243a37065"},
    {65000,     "c7be8e9e9124087361b7979a8642e73061740fa5d5eb86472b9e9f60085b59be"},
    {70000,     "d18da06bc82afe85d95e4332db109dc2d615be4840adb3323bca1393289a44a0"},
    {75000,     "3f58e09feefb310e47b8d435482c996cb832f1809b7219ed48b8c63996e79f69"},
    {80000,     "fb3d92396c33cdb5706aadfdda17828df651e0bbc6f3deb03976d4c110c45080"},
    {85000,     "044dd3ba96e0d8500cde7c8d8eaefb3e9a7c31a01ef51fb985aeafca1af9efd2"},
    {90000,     "5a13d7e709b0d138d9c2c768adc09d2a8884fb91cb915411269def7e79314e3a"},
    {95000,     "c1a4f04975904eea805cb5436763391fb64defd50f125542d2c2ebc092925989"},
    {100000,    "c41849d4a986517af061e0180d29f3a42f26c17b25cd6173cc77707140de14a1"},
    {105000,    "f8f6955dc45a6b910fe7086b34769b405b437c42d0e52dfb99582ceb887daa83"},
};
}
