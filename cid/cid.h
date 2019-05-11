#pragma once

#include <multibase/multibase.h>
#include <multihash/multihash.h>
#include <memory>
#include <string>

namespace cid {

template <typename Container = std::string>
class cid {
 public:
  /** Create a CID from data */
  explicit cid(Container data);

  /** Create a V0 CID from a multihash */
  explicit cid(multi::Hash contentAddress);

  /** Get the base in which this CID is encoded */
  varint::uleb128<std::string_view> base() const;

  /** Get the CID version */
  version_t version() const;
  /** Get the content type */
  multicodec::algorithm::code_type codec() const;
  /** Get the content address */
  multihash<std::string_view> hash() const;

 private:
  Container data_;
};

}  // namespace cid