#pragma once
#include <fstream>
#include <string>

inline std::string calculateCPU() {
  std::ifstream filestat("/proc/stat");
  std::string line;
  std::getline(filestat, line);
  // TODO: computed as described here: http://stackoverflow.com/questions/23367857/accurate-calculation-of-cpu-usage-given-in -percentage-in-linux/

  return line;
}
inline std::string calculateRAM() {
  // TODO:Properly parse all the lines to read memtotal, memfree, buffers, cached
  // TODO: compute the usage like: MemTotal - MemFree - Buffers - Cached
  std::ifstream filestat("/proc/meminfo");
  std::string line;
  std::getline(filestat, line);

  return line;
}
