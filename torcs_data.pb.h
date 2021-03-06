// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: torcs_data.proto

#ifndef PROTOBUF_torcs_5fdata_2eproto__INCLUDED
#define PROTOBUF_torcs_5fdata_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_torcs_5fdata_2eproto();
void protobuf_AssignDesc_torcs_5fdata_2eproto();
void protobuf_ShutdownFile_torcs_5fdata_2eproto();

class TorcsData;

// ===================================================================

class TorcsData : public ::google::protobuf::Message {
 public:
  TorcsData();
  virtual ~TorcsData();

  TorcsData(const TorcsData& from);

  inline TorcsData& operator=(const TorcsData& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const TorcsData& default_instance();

  void Swap(TorcsData* other);

  // implements Message ----------------------------------------------

  TorcsData* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const TorcsData& from);
  void MergeFrom(const TorcsData& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated int32 width = 1;
  inline int width_size() const;
  inline void clear_width();
  static const int kWidthFieldNumber = 1;
  inline ::google::protobuf::int32 width(int index) const;
  inline void set_width(int index, ::google::protobuf::int32 value);
  inline void add_width(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      width() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_width();

  // repeated int32 height = 2;
  inline int height_size() const;
  inline void clear_height();
  static const int kHeightFieldNumber = 2;
  inline ::google::protobuf::int32 height(int index) const;
  inline void set_height(int index, ::google::protobuf::int32 value);
  inline void add_height(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      height() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_height();

  // repeated bytes image = 3;
  inline int image_size() const;
  inline void clear_image();
  static const int kImageFieldNumber = 3;
  inline const ::std::string& image(int index) const;
  inline ::std::string* mutable_image(int index);
  inline void set_image(int index, const ::std::string& value);
  inline void set_image(int index, const char* value);
  inline void set_image(int index, const void* value, size_t size);
  inline ::std::string* add_image();
  inline void add_image(const ::std::string& value);
  inline void add_image(const char* value);
  inline void add_image(const void* value, size_t size);
  inline const ::google::protobuf::RepeatedPtrField< ::std::string>& image() const;
  inline ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_image();

  // repeated int32 save_flag = 4;
  inline int save_flag_size() const;
  inline void clear_save_flag();
  static const int kSaveFlagFieldNumber = 4;
  inline ::google::protobuf::int32 save_flag(int index) const;
  inline void set_save_flag(int index, ::google::protobuf::int32 value);
  inline void add_save_flag(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      save_flag() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_save_flag();

  // repeated double steer_angle = 5;
  inline int steer_angle_size() const;
  inline void clear_steer_angle();
  static const int kSteerAngleFieldNumber = 5;
  inline double steer_angle(int index) const;
  inline void set_steer_angle(int index, double value);
  inline void add_steer_angle(double value);
  inline const ::google::protobuf::RepeatedField< double >&
      steer_angle() const;
  inline ::google::protobuf::RepeatedField< double >*
      mutable_steer_angle();

  // repeated bytes red = 6;
  inline int red_size() const;
  inline void clear_red();
  static const int kRedFieldNumber = 6;
  inline const ::std::string& red(int index) const;
  inline ::std::string* mutable_red(int index);
  inline void set_red(int index, const ::std::string& value);
  inline void set_red(int index, const char* value);
  inline void set_red(int index, const void* value, size_t size);
  inline ::std::string* add_red();
  inline void add_red(const ::std::string& value);
  inline void add_red(const char* value);
  inline void add_red(const void* value, size_t size);
  inline const ::google::protobuf::RepeatedPtrField< ::std::string>& red() const;
  inline ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_red();

  // repeated bytes green = 7;
  inline int green_size() const;
  inline void clear_green();
  static const int kGreenFieldNumber = 7;
  inline const ::std::string& green(int index) const;
  inline ::std::string* mutable_green(int index);
  inline void set_green(int index, const ::std::string& value);
  inline void set_green(int index, const char* value);
  inline void set_green(int index, const void* value, size_t size);
  inline ::std::string* add_green();
  inline void add_green(const ::std::string& value);
  inline void add_green(const char* value);
  inline void add_green(const void* value, size_t size);
  inline const ::google::protobuf::RepeatedPtrField< ::std::string>& green() const;
  inline ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_green();

  // repeated bytes blue = 8;
  inline int blue_size() const;
  inline void clear_blue();
  static const int kBlueFieldNumber = 8;
  inline const ::std::string& blue(int index) const;
  inline ::std::string* mutable_blue(int index);
  inline void set_blue(int index, const ::std::string& value);
  inline void set_blue(int index, const char* value);
  inline void set_blue(int index, const void* value, size_t size);
  inline ::std::string* add_blue();
  inline void add_blue(const ::std::string& value);
  inline void add_blue(const char* value);
  inline void add_blue(const void* value, size_t size);
  inline const ::google::protobuf::RepeatedPtrField< ::std::string>& blue() const;
  inline ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_blue();

  // @@protoc_insertion_point(class_scope:TorcsData)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > width_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > height_;
  ::google::protobuf::RepeatedPtrField< ::std::string> image_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > save_flag_;
  ::google::protobuf::RepeatedField< double > steer_angle_;
  ::google::protobuf::RepeatedPtrField< ::std::string> red_;
  ::google::protobuf::RepeatedPtrField< ::std::string> green_;
  ::google::protobuf::RepeatedPtrField< ::std::string> blue_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(8 + 31) / 32];

  friend void  protobuf_AddDesc_torcs_5fdata_2eproto();
  friend void protobuf_AssignDesc_torcs_5fdata_2eproto();
  friend void protobuf_ShutdownFile_torcs_5fdata_2eproto();

  void InitAsDefaultInstance();
  static TorcsData* default_instance_;
};
// ===================================================================


// ===================================================================

// TorcsData

// repeated int32 width = 1;
inline int TorcsData::width_size() const {
  return width_.size();
}
inline void TorcsData::clear_width() {
  width_.Clear();
}
inline ::google::protobuf::int32 TorcsData::width(int index) const {
  return width_.Get(index);
}
inline void TorcsData::set_width(int index, ::google::protobuf::int32 value) {
  width_.Set(index, value);
}
inline void TorcsData::add_width(::google::protobuf::int32 value) {
  width_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
TorcsData::width() const {
  return width_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
TorcsData::mutable_width() {
  return &width_;
}

// repeated int32 height = 2;
inline int TorcsData::height_size() const {
  return height_.size();
}
inline void TorcsData::clear_height() {
  height_.Clear();
}
inline ::google::protobuf::int32 TorcsData::height(int index) const {
  return height_.Get(index);
}
inline void TorcsData::set_height(int index, ::google::protobuf::int32 value) {
  height_.Set(index, value);
}
inline void TorcsData::add_height(::google::protobuf::int32 value) {
  height_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
TorcsData::height() const {
  return height_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
TorcsData::mutable_height() {
  return &height_;
}

// repeated bytes image = 3;
inline int TorcsData::image_size() const {
  return image_.size();
}
inline void TorcsData::clear_image() {
  image_.Clear();
}
inline const ::std::string& TorcsData::image(int index) const {
  return image_.Get(index);
}
inline ::std::string* TorcsData::mutable_image(int index) {
  return image_.Mutable(index);
}
inline void TorcsData::set_image(int index, const ::std::string& value) {
  image_.Mutable(index)->assign(value);
}
inline void TorcsData::set_image(int index, const char* value) {
  image_.Mutable(index)->assign(value);
}
inline void TorcsData::set_image(int index, const void* value, size_t size) {
  image_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
}
inline ::std::string* TorcsData::add_image() {
  return image_.Add();
}
inline void TorcsData::add_image(const ::std::string& value) {
  image_.Add()->assign(value);
}
inline void TorcsData::add_image(const char* value) {
  image_.Add()->assign(value);
}
inline void TorcsData::add_image(const void* value, size_t size) {
  image_.Add()->assign(reinterpret_cast<const char*>(value), size);
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
TorcsData::image() const {
  return image_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
TorcsData::mutable_image() {
  return &image_;
}

// repeated int32 save_flag = 4;
inline int TorcsData::save_flag_size() const {
  return save_flag_.size();
}
inline void TorcsData::clear_save_flag() {
  save_flag_.Clear();
}
inline ::google::protobuf::int32 TorcsData::save_flag(int index) const {
  return save_flag_.Get(index);
}
inline void TorcsData::set_save_flag(int index, ::google::protobuf::int32 value) {
  save_flag_.Set(index, value);
}
inline void TorcsData::add_save_flag(::google::protobuf::int32 value) {
  save_flag_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
TorcsData::save_flag() const {
  return save_flag_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
TorcsData::mutable_save_flag() {
  return &save_flag_;
}

// repeated double steer_angle = 5;
inline int TorcsData::steer_angle_size() const {
  return steer_angle_.size();
}
inline void TorcsData::clear_steer_angle() {
  steer_angle_.Clear();
}
inline double TorcsData::steer_angle(int index) const {
  return steer_angle_.Get(index);
}
inline void TorcsData::set_steer_angle(int index, double value) {
  steer_angle_.Set(index, value);
}
inline void TorcsData::add_steer_angle(double value) {
  steer_angle_.Add(value);
}
inline const ::google::protobuf::RepeatedField< double >&
TorcsData::steer_angle() const {
  return steer_angle_;
}
inline ::google::protobuf::RepeatedField< double >*
TorcsData::mutable_steer_angle() {
  return &steer_angle_;
}

// repeated bytes red = 6;
inline int TorcsData::red_size() const {
  return red_.size();
}
inline void TorcsData::clear_red() {
  red_.Clear();
}
inline const ::std::string& TorcsData::red(int index) const {
  return red_.Get(index);
}
inline ::std::string* TorcsData::mutable_red(int index) {
  return red_.Mutable(index);
}
inline void TorcsData::set_red(int index, const ::std::string& value) {
  red_.Mutable(index)->assign(value);
}
inline void TorcsData::set_red(int index, const char* value) {
  red_.Mutable(index)->assign(value);
}
inline void TorcsData::set_red(int index, const void* value, size_t size) {
  red_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
}
inline ::std::string* TorcsData::add_red() {
  return red_.Add();
}
inline void TorcsData::add_red(const ::std::string& value) {
  red_.Add()->assign(value);
}
inline void TorcsData::add_red(const char* value) {
  red_.Add()->assign(value);
}
inline void TorcsData::add_red(const void* value, size_t size) {
  red_.Add()->assign(reinterpret_cast<const char*>(value), size);
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
TorcsData::red() const {
  return red_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
TorcsData::mutable_red() {
  return &red_;
}

// repeated bytes green = 7;
inline int TorcsData::green_size() const {
  return green_.size();
}
inline void TorcsData::clear_green() {
  green_.Clear();
}
inline const ::std::string& TorcsData::green(int index) const {
  return green_.Get(index);
}
inline ::std::string* TorcsData::mutable_green(int index) {
  return green_.Mutable(index);
}
inline void TorcsData::set_green(int index, const ::std::string& value) {
  green_.Mutable(index)->assign(value);
}
inline void TorcsData::set_green(int index, const char* value) {
  green_.Mutable(index)->assign(value);
}
inline void TorcsData::set_green(int index, const void* value, size_t size) {
  green_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
}
inline ::std::string* TorcsData::add_green() {
  return green_.Add();
}
inline void TorcsData::add_green(const ::std::string& value) {
  green_.Add()->assign(value);
}
inline void TorcsData::add_green(const char* value) {
  green_.Add()->assign(value);
}
inline void TorcsData::add_green(const void* value, size_t size) {
  green_.Add()->assign(reinterpret_cast<const char*>(value), size);
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
TorcsData::green() const {
  return green_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
TorcsData::mutable_green() {
  return &green_;
}

// repeated bytes blue = 8;
inline int TorcsData::blue_size() const {
  return blue_.size();
}
inline void TorcsData::clear_blue() {
  blue_.Clear();
}
inline const ::std::string& TorcsData::blue(int index) const {
  return blue_.Get(index);
}
inline ::std::string* TorcsData::mutable_blue(int index) {
  return blue_.Mutable(index);
}
inline void TorcsData::set_blue(int index, const ::std::string& value) {
  blue_.Mutable(index)->assign(value);
}
inline void TorcsData::set_blue(int index, const char* value) {
  blue_.Mutable(index)->assign(value);
}
inline void TorcsData::set_blue(int index, const void* value, size_t size) {
  blue_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
}
inline ::std::string* TorcsData::add_blue() {
  return blue_.Add();
}
inline void TorcsData::add_blue(const ::std::string& value) {
  blue_.Add()->assign(value);
}
inline void TorcsData::add_blue(const char* value) {
  blue_.Add()->assign(value);
}
inline void TorcsData::add_blue(const void* value, size_t size) {
  blue_.Add()->assign(reinterpret_cast<const char*>(value), size);
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
TorcsData::blue() const {
  return blue_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
TorcsData::mutable_blue() {
  return &blue_;
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_torcs_5fdata_2eproto__INCLUDED
