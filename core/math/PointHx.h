#ifndef POINTHX_H
#define POINTHX_H
#include <string>
#include <cstdint>

struct PointHX {
public:
  PointHX(int x, int y, int z) : x(x), y(y), z(z){};
  PointHX() = default;
  int x, y, z;
  bool operator==(const PointHX& rhs) const;
  bool operator!=(const PointHX& rhs) const;
  PointHX& operator=(const PointHX& rhs);
  PointHX operator+(const PointHX& rhs) const;
  PointHX& operator+=(const PointHX& rhs);
  PointHX operator-(const PointHX& rhs) const;
  PointHX& operator-=(const PointHX& rhs);

  inline PointHX Ne() const { return *this + NE; }

  const static PointHX NE;
  const static PointHX E;
  const static PointHX SE;
  const static PointHX SW;
  const static PointHX W;
  const static PointHX NW;
  const static PointHX INFINITE;
  std::string to_string();

  // for unordered set
  //size_t operator()(const PointHX& p) const noexcept { return ((uint64_t)p.x) << 32 | (uint64_t)p.y; };

  //uint64_t hash(PointHX const& p) const noexcept { return ((uint64_t)p.x) << 32 | (uint64_t)p.y; }
};
/*
namespace std {
  template <> struct hash<PointHX> {
    std::size_t operator()(const PointHX& p) const noexcept { return p(p); }
  };
} */  // namespace std

#endif  // PointHX_H
