#pragma once

#include <thread>
#include <mutex>

#include "cpu.hpp"
#include "amdcpu.hpp"
#include "intelcpu.hpp"
#include "memory.hpp"
#include "gpu.hpp"
// #include "amdgpu.hpp"
#include "nvidiagpu.hpp"
#include "network.hpp"
#include "systime.hpp"

class Serializer
{
public:
    Serializer();
    ~Serializer();
    void SerializeInitInfo(BYTE *buf, int len);
    void SerializeSystemInfo(BYTE *buf, int len);

private:
    CPU::InfoGetter *cpu;
    CPU::Info cpuInfo;
    std::mutex cpuInfoMutex;
    bool cpuInfoGetterDone = false;
    std::thread *cpuInfoGetter;

    GPU::InfoGetter *gpu;
    GPU::Info gpuInfo;
    std::mutex gpuInfoMutex;
    bool gpuInfoGetterDone = false;
    std::thread *gpuInfoGetter;

    Network::InfoGetter network;
    Network::Info networkInfo;
    std::mutex networkInfoMutex;
    bool networkInfoGetterDone = false;
    std::thread *networkInfoGetter;

    Memory::InfoGetter mem;
    SystemTime::Time time;
};