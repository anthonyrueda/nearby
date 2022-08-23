// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: internal/proto/device_metadata.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_internal_2fproto_2fdevice_5fmetadata_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_internal_2fproto_2fdevice_5fmetadata_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021005 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_internal_2fproto_2fdevice_5fmetadata_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_internal_2fproto_2fdevice_5fmetadata_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_internal_2fproto_2fdevice_5fmetadata_2eproto;
namespace nearby {
namespace internal {
class DeviceMetadata;
struct DeviceMetadataDefaultTypeInternal;
extern DeviceMetadataDefaultTypeInternal _DeviceMetadata_default_instance_;
}  // namespace internal
}  // namespace nearby
PROTOBUF_NAMESPACE_OPEN
template<> ::nearby::internal::DeviceMetadata* Arena::CreateMaybeMessage<::nearby::internal::DeviceMetadata>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace nearby {
namespace internal {

enum DeviceMetadata_DeviceType : int {
  DeviceMetadata_DeviceType_UNSPECIFIED = 0,
  DeviceMetadata_DeviceType_PHONE = 1,
  DeviceMetadata_DeviceType_TABLET = 2,
  DeviceMetadata_DeviceType_DISPLAY = 3,
  DeviceMetadata_DeviceType_LAPTOP = 4,
  DeviceMetadata_DeviceType_TV = 5,
  DeviceMetadata_DeviceType_WATCH = 6,
  DeviceMetadata_DeviceType_DeviceMetadata_DeviceType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  DeviceMetadata_DeviceType_DeviceMetadata_DeviceType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool DeviceMetadata_DeviceType_IsValid(int value);
constexpr DeviceMetadata_DeviceType DeviceMetadata_DeviceType_DeviceType_MIN = DeviceMetadata_DeviceType_UNSPECIFIED;
constexpr DeviceMetadata_DeviceType DeviceMetadata_DeviceType_DeviceType_MAX = DeviceMetadata_DeviceType_WATCH;
constexpr int DeviceMetadata_DeviceType_DeviceType_ARRAYSIZE = DeviceMetadata_DeviceType_DeviceType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* DeviceMetadata_DeviceType_descriptor();
template<typename T>
inline const std::string& DeviceMetadata_DeviceType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, DeviceMetadata_DeviceType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function DeviceMetadata_DeviceType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    DeviceMetadata_DeviceType_descriptor(), enum_t_value);
}
inline bool DeviceMetadata_DeviceType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, DeviceMetadata_DeviceType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<DeviceMetadata_DeviceType>(
    DeviceMetadata_DeviceType_descriptor(), name, value);
}
// ===================================================================

class DeviceMetadata final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:nearby.internal.DeviceMetadata) */ {
 public:
  inline DeviceMetadata() : DeviceMetadata(nullptr) {}
  ~DeviceMetadata() override;
  explicit PROTOBUF_CONSTEXPR DeviceMetadata(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  DeviceMetadata(const DeviceMetadata& from);
  DeviceMetadata(DeviceMetadata&& from) noexcept
    : DeviceMetadata() {
    *this = ::std::move(from);
  }

  inline DeviceMetadata& operator=(const DeviceMetadata& from) {
    CopyFrom(from);
    return *this;
  }
  inline DeviceMetadata& operator=(DeviceMetadata&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const DeviceMetadata& default_instance() {
    return *internal_default_instance();
  }
  static inline const DeviceMetadata* internal_default_instance() {
    return reinterpret_cast<const DeviceMetadata*>(
               &_DeviceMetadata_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(DeviceMetadata& a, DeviceMetadata& b) {
    a.Swap(&b);
  }
  inline void Swap(DeviceMetadata* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(DeviceMetadata* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  DeviceMetadata* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<DeviceMetadata>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const DeviceMetadata& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const DeviceMetadata& from) {
    DeviceMetadata::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(DeviceMetadata* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "nearby.internal.DeviceMetadata";
  }
  protected:
  explicit DeviceMetadata(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef DeviceMetadata_DeviceType DeviceType;
  static constexpr DeviceType UNSPECIFIED =
    DeviceMetadata_DeviceType_UNSPECIFIED;
  static constexpr DeviceType PHONE =
    DeviceMetadata_DeviceType_PHONE;
  static constexpr DeviceType TABLET =
    DeviceMetadata_DeviceType_TABLET;
  static constexpr DeviceType DISPLAY =
    DeviceMetadata_DeviceType_DISPLAY;
  static constexpr DeviceType LAPTOP =
    DeviceMetadata_DeviceType_LAPTOP;
  static constexpr DeviceType TV =
    DeviceMetadata_DeviceType_TV;
  static constexpr DeviceType WATCH =
    DeviceMetadata_DeviceType_WATCH;
  static inline bool DeviceType_IsValid(int value) {
    return DeviceMetadata_DeviceType_IsValid(value);
  }
  static constexpr DeviceType DeviceType_MIN =
    DeviceMetadata_DeviceType_DeviceType_MIN;
  static constexpr DeviceType DeviceType_MAX =
    DeviceMetadata_DeviceType_DeviceType_MAX;
  static constexpr int DeviceType_ARRAYSIZE =
    DeviceMetadata_DeviceType_DeviceType_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  DeviceType_descriptor() {
    return DeviceMetadata_DeviceType_descriptor();
  }
  template<typename T>
  static inline const std::string& DeviceType_Name(T enum_t_value) {
    static_assert(::std::is_same<T, DeviceType>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function DeviceType_Name.");
    return DeviceMetadata_DeviceType_Name(enum_t_value);
  }
  static inline bool DeviceType_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      DeviceType* value) {
    return DeviceMetadata_DeviceType_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kStableDeviceIdFieldNumber = 1,
    kAccountNameFieldNumber = 2,
    kDeviceNameFieldNumber = 3,
    kIconUrlFieldNumber = 4,
    kBluetoothMacAddressFieldNumber = 5,
    kDeviceTypeFieldNumber = 6,
  };
  // optional string stable_device_id = 1;
  bool has_stable_device_id() const;
  private:
  bool _internal_has_stable_device_id() const;
  public:
  void clear_stable_device_id();
  const std::string& stable_device_id() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_stable_device_id(ArgT0&& arg0, ArgT... args);
  std::string* mutable_stable_device_id();
  PROTOBUF_NODISCARD std::string* release_stable_device_id();
  void set_allocated_stable_device_id(std::string* stable_device_id);
  private:
  const std::string& _internal_stable_device_id() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_stable_device_id(const std::string& value);
  std::string* _internal_mutable_stable_device_id();
  public:

  // optional string account_name = 2;
  bool has_account_name() const;
  private:
  bool _internal_has_account_name() const;
  public:
  void clear_account_name();
  const std::string& account_name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_account_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_account_name();
  PROTOBUF_NODISCARD std::string* release_account_name();
  void set_allocated_account_name(std::string* account_name);
  private:
  const std::string& _internal_account_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_account_name(const std::string& value);
  std::string* _internal_mutable_account_name();
  public:

  // optional string device_name = 3;
  bool has_device_name() const;
  private:
  bool _internal_has_device_name() const;
  public:
  void clear_device_name();
  const std::string& device_name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_device_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_device_name();
  PROTOBUF_NODISCARD std::string* release_device_name();
  void set_allocated_device_name(std::string* device_name);
  private:
  const std::string& _internal_device_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_device_name(const std::string& value);
  std::string* _internal_mutable_device_name();
  public:

  // optional string icon_url = 4;
  bool has_icon_url() const;
  private:
  bool _internal_has_icon_url() const;
  public:
  void clear_icon_url();
  const std::string& icon_url() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_icon_url(ArgT0&& arg0, ArgT... args);
  std::string* mutable_icon_url();
  PROTOBUF_NODISCARD std::string* release_icon_url();
  void set_allocated_icon_url(std::string* icon_url);
  private:
  const std::string& _internal_icon_url() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_icon_url(const std::string& value);
  std::string* _internal_mutable_icon_url();
  public:

  // optional string bluetooth_mac_address = 5;
  bool has_bluetooth_mac_address() const;
  private:
  bool _internal_has_bluetooth_mac_address() const;
  public:
  void clear_bluetooth_mac_address();
  const std::string& bluetooth_mac_address() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_bluetooth_mac_address(ArgT0&& arg0, ArgT... args);
  std::string* mutable_bluetooth_mac_address();
  PROTOBUF_NODISCARD std::string* release_bluetooth_mac_address();
  void set_allocated_bluetooth_mac_address(std::string* bluetooth_mac_address);
  private:
  const std::string& _internal_bluetooth_mac_address() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_bluetooth_mac_address(const std::string& value);
  std::string* _internal_mutable_bluetooth_mac_address();
  public:

  // optional .nearby.internal.DeviceMetadata.DeviceType device_type = 6;
  bool has_device_type() const;
  private:
  bool _internal_has_device_type() const;
  public:
  void clear_device_type();
  ::nearby::internal::DeviceMetadata_DeviceType device_type() const;
  void set_device_type(::nearby::internal::DeviceMetadata_DeviceType value);
  private:
  ::nearby::internal::DeviceMetadata_DeviceType _internal_device_type() const;
  void _internal_set_device_type(::nearby::internal::DeviceMetadata_DeviceType value);
  public:

  // @@protoc_insertion_point(class_scope:nearby.internal.DeviceMetadata)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr stable_device_id_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr account_name_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr device_name_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr icon_url_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr bluetooth_mac_address_;
    int device_type_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_internal_2fproto_2fdevice_5fmetadata_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// DeviceMetadata

// optional string stable_device_id = 1;
inline bool DeviceMetadata::_internal_has_stable_device_id() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool DeviceMetadata::has_stable_device_id() const {
  return _internal_has_stable_device_id();
}
inline void DeviceMetadata::clear_stable_device_id() {
  _impl_.stable_device_id_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& DeviceMetadata::stable_device_id() const {
  // @@protoc_insertion_point(field_get:nearby.internal.DeviceMetadata.stable_device_id)
  return _internal_stable_device_id();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void DeviceMetadata::set_stable_device_id(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000001u;
 _impl_.stable_device_id_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:nearby.internal.DeviceMetadata.stable_device_id)
}
inline std::string* DeviceMetadata::mutable_stable_device_id() {
  std::string* _s = _internal_mutable_stable_device_id();
  // @@protoc_insertion_point(field_mutable:nearby.internal.DeviceMetadata.stable_device_id)
  return _s;
}
inline const std::string& DeviceMetadata::_internal_stable_device_id() const {
  return _impl_.stable_device_id_.Get();
}
inline void DeviceMetadata::_internal_set_stable_device_id(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.stable_device_id_.Set(value, GetArenaForAllocation());
}
inline std::string* DeviceMetadata::_internal_mutable_stable_device_id() {
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.stable_device_id_.Mutable(GetArenaForAllocation());
}
inline std::string* DeviceMetadata::release_stable_device_id() {
  // @@protoc_insertion_point(field_release:nearby.internal.DeviceMetadata.stable_device_id)
  if (!_internal_has_stable_device_id()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* p = _impl_.stable_device_id_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.stable_device_id_.IsDefault()) {
    _impl_.stable_device_id_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void DeviceMetadata::set_allocated_stable_device_id(std::string* stable_device_id) {
  if (stable_device_id != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.stable_device_id_.SetAllocated(stable_device_id, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.stable_device_id_.IsDefault()) {
    _impl_.stable_device_id_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:nearby.internal.DeviceMetadata.stable_device_id)
}

// optional string account_name = 2;
inline bool DeviceMetadata::_internal_has_account_name() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool DeviceMetadata::has_account_name() const {
  return _internal_has_account_name();
}
inline void DeviceMetadata::clear_account_name() {
  _impl_.account_name_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline const std::string& DeviceMetadata::account_name() const {
  // @@protoc_insertion_point(field_get:nearby.internal.DeviceMetadata.account_name)
  return _internal_account_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void DeviceMetadata::set_account_name(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000002u;
 _impl_.account_name_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:nearby.internal.DeviceMetadata.account_name)
}
inline std::string* DeviceMetadata::mutable_account_name() {
  std::string* _s = _internal_mutable_account_name();
  // @@protoc_insertion_point(field_mutable:nearby.internal.DeviceMetadata.account_name)
  return _s;
}
inline const std::string& DeviceMetadata::_internal_account_name() const {
  return _impl_.account_name_.Get();
}
inline void DeviceMetadata::_internal_set_account_name(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.account_name_.Set(value, GetArenaForAllocation());
}
inline std::string* DeviceMetadata::_internal_mutable_account_name() {
  _impl_._has_bits_[0] |= 0x00000002u;
  return _impl_.account_name_.Mutable(GetArenaForAllocation());
}
inline std::string* DeviceMetadata::release_account_name() {
  // @@protoc_insertion_point(field_release:nearby.internal.DeviceMetadata.account_name)
  if (!_internal_has_account_name()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000002u;
  auto* p = _impl_.account_name_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.account_name_.IsDefault()) {
    _impl_.account_name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void DeviceMetadata::set_allocated_account_name(std::string* account_name) {
  if (account_name != nullptr) {
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  _impl_.account_name_.SetAllocated(account_name, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.account_name_.IsDefault()) {
    _impl_.account_name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:nearby.internal.DeviceMetadata.account_name)
}

// optional string device_name = 3;
inline bool DeviceMetadata::_internal_has_device_name() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool DeviceMetadata::has_device_name() const {
  return _internal_has_device_name();
}
inline void DeviceMetadata::clear_device_name() {
  _impl_.device_name_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000004u;
}
inline const std::string& DeviceMetadata::device_name() const {
  // @@protoc_insertion_point(field_get:nearby.internal.DeviceMetadata.device_name)
  return _internal_device_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void DeviceMetadata::set_device_name(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000004u;
 _impl_.device_name_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:nearby.internal.DeviceMetadata.device_name)
}
inline std::string* DeviceMetadata::mutable_device_name() {
  std::string* _s = _internal_mutable_device_name();
  // @@protoc_insertion_point(field_mutable:nearby.internal.DeviceMetadata.device_name)
  return _s;
}
inline const std::string& DeviceMetadata::_internal_device_name() const {
  return _impl_.device_name_.Get();
}
inline void DeviceMetadata::_internal_set_device_name(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000004u;
  _impl_.device_name_.Set(value, GetArenaForAllocation());
}
inline std::string* DeviceMetadata::_internal_mutable_device_name() {
  _impl_._has_bits_[0] |= 0x00000004u;
  return _impl_.device_name_.Mutable(GetArenaForAllocation());
}
inline std::string* DeviceMetadata::release_device_name() {
  // @@protoc_insertion_point(field_release:nearby.internal.DeviceMetadata.device_name)
  if (!_internal_has_device_name()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000004u;
  auto* p = _impl_.device_name_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.device_name_.IsDefault()) {
    _impl_.device_name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void DeviceMetadata::set_allocated_device_name(std::string* device_name) {
  if (device_name != nullptr) {
    _impl_._has_bits_[0] |= 0x00000004u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000004u;
  }
  _impl_.device_name_.SetAllocated(device_name, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.device_name_.IsDefault()) {
    _impl_.device_name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:nearby.internal.DeviceMetadata.device_name)
}

// optional string icon_url = 4;
inline bool DeviceMetadata::_internal_has_icon_url() const {
  bool value = (_impl_._has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool DeviceMetadata::has_icon_url() const {
  return _internal_has_icon_url();
}
inline void DeviceMetadata::clear_icon_url() {
  _impl_.icon_url_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000008u;
}
inline const std::string& DeviceMetadata::icon_url() const {
  // @@protoc_insertion_point(field_get:nearby.internal.DeviceMetadata.icon_url)
  return _internal_icon_url();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void DeviceMetadata::set_icon_url(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000008u;
 _impl_.icon_url_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:nearby.internal.DeviceMetadata.icon_url)
}
inline std::string* DeviceMetadata::mutable_icon_url() {
  std::string* _s = _internal_mutable_icon_url();
  // @@protoc_insertion_point(field_mutable:nearby.internal.DeviceMetadata.icon_url)
  return _s;
}
inline const std::string& DeviceMetadata::_internal_icon_url() const {
  return _impl_.icon_url_.Get();
}
inline void DeviceMetadata::_internal_set_icon_url(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000008u;
  _impl_.icon_url_.Set(value, GetArenaForAllocation());
}
inline std::string* DeviceMetadata::_internal_mutable_icon_url() {
  _impl_._has_bits_[0] |= 0x00000008u;
  return _impl_.icon_url_.Mutable(GetArenaForAllocation());
}
inline std::string* DeviceMetadata::release_icon_url() {
  // @@protoc_insertion_point(field_release:nearby.internal.DeviceMetadata.icon_url)
  if (!_internal_has_icon_url()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000008u;
  auto* p = _impl_.icon_url_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.icon_url_.IsDefault()) {
    _impl_.icon_url_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void DeviceMetadata::set_allocated_icon_url(std::string* icon_url) {
  if (icon_url != nullptr) {
    _impl_._has_bits_[0] |= 0x00000008u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000008u;
  }
  _impl_.icon_url_.SetAllocated(icon_url, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.icon_url_.IsDefault()) {
    _impl_.icon_url_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:nearby.internal.DeviceMetadata.icon_url)
}

// optional string bluetooth_mac_address = 5;
inline bool DeviceMetadata::_internal_has_bluetooth_mac_address() const {
  bool value = (_impl_._has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline bool DeviceMetadata::has_bluetooth_mac_address() const {
  return _internal_has_bluetooth_mac_address();
}
inline void DeviceMetadata::clear_bluetooth_mac_address() {
  _impl_.bluetooth_mac_address_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000010u;
}
inline const std::string& DeviceMetadata::bluetooth_mac_address() const {
  // @@protoc_insertion_point(field_get:nearby.internal.DeviceMetadata.bluetooth_mac_address)
  return _internal_bluetooth_mac_address();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void DeviceMetadata::set_bluetooth_mac_address(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000010u;
 _impl_.bluetooth_mac_address_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:nearby.internal.DeviceMetadata.bluetooth_mac_address)
}
inline std::string* DeviceMetadata::mutable_bluetooth_mac_address() {
  std::string* _s = _internal_mutable_bluetooth_mac_address();
  // @@protoc_insertion_point(field_mutable:nearby.internal.DeviceMetadata.bluetooth_mac_address)
  return _s;
}
inline const std::string& DeviceMetadata::_internal_bluetooth_mac_address() const {
  return _impl_.bluetooth_mac_address_.Get();
}
inline void DeviceMetadata::_internal_set_bluetooth_mac_address(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000010u;
  _impl_.bluetooth_mac_address_.Set(value, GetArenaForAllocation());
}
inline std::string* DeviceMetadata::_internal_mutable_bluetooth_mac_address() {
  _impl_._has_bits_[0] |= 0x00000010u;
  return _impl_.bluetooth_mac_address_.Mutable(GetArenaForAllocation());
}
inline std::string* DeviceMetadata::release_bluetooth_mac_address() {
  // @@protoc_insertion_point(field_release:nearby.internal.DeviceMetadata.bluetooth_mac_address)
  if (!_internal_has_bluetooth_mac_address()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000010u;
  auto* p = _impl_.bluetooth_mac_address_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.bluetooth_mac_address_.IsDefault()) {
    _impl_.bluetooth_mac_address_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void DeviceMetadata::set_allocated_bluetooth_mac_address(std::string* bluetooth_mac_address) {
  if (bluetooth_mac_address != nullptr) {
    _impl_._has_bits_[0] |= 0x00000010u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000010u;
  }
  _impl_.bluetooth_mac_address_.SetAllocated(bluetooth_mac_address, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.bluetooth_mac_address_.IsDefault()) {
    _impl_.bluetooth_mac_address_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:nearby.internal.DeviceMetadata.bluetooth_mac_address)
}

// optional .nearby.internal.DeviceMetadata.DeviceType device_type = 6;
inline bool DeviceMetadata::_internal_has_device_type() const {
  bool value = (_impl_._has_bits_[0] & 0x00000020u) != 0;
  return value;
}
inline bool DeviceMetadata::has_device_type() const {
  return _internal_has_device_type();
}
inline void DeviceMetadata::clear_device_type() {
  _impl_.device_type_ = 0;
  _impl_._has_bits_[0] &= ~0x00000020u;
}
inline ::nearby::internal::DeviceMetadata_DeviceType DeviceMetadata::_internal_device_type() const {
  return static_cast< ::nearby::internal::DeviceMetadata_DeviceType >(_impl_.device_type_);
}
inline ::nearby::internal::DeviceMetadata_DeviceType DeviceMetadata::device_type() const {
  // @@protoc_insertion_point(field_get:nearby.internal.DeviceMetadata.device_type)
  return _internal_device_type();
}
inline void DeviceMetadata::_internal_set_device_type(::nearby::internal::DeviceMetadata_DeviceType value) {
  _impl_._has_bits_[0] |= 0x00000020u;
  _impl_.device_type_ = value;
}
inline void DeviceMetadata::set_device_type(::nearby::internal::DeviceMetadata_DeviceType value) {
  _internal_set_device_type(value);
  // @@protoc_insertion_point(field_set:nearby.internal.DeviceMetadata.device_type)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace internal
}  // namespace nearby

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::nearby::internal::DeviceMetadata_DeviceType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::nearby::internal::DeviceMetadata_DeviceType>() {
  return ::nearby::internal::DeviceMetadata_DeviceType_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_internal_2fproto_2fdevice_5fmetadata_2eproto
