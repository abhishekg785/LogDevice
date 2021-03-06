// @generated
// automatically generated by the FlatBuffers compiler, do not modify

#ifndef FLATBUFFERS_GENERATED_CLUSTERMAINTENANCELOGRECORD_FACEBOOK_LOGDEVICE_CLUSTER_MAINTENANCE_LOG_RECORD_FBUFFERS_H_
#define FLATBUFFERS_GENERATED_CLUSTERMAINTENANCELOGRECORD_FACEBOOK_LOGDEVICE_CLUSTER_MAINTENANCE_LOG_RECORD_FBUFFERS_H_

#include "flatbuffers/flatbuffers.h"

namespace facebook {
namespace logdevice {
namespace cluster_maintenance_log_record {
namespace fbuffers {

struct ShardID;

struct ShardMaintenance;

struct SequencerMaintenance;

struct ExtraAttr;

struct MaintenanceHeader;

struct ApplyMaintenance;

struct RemoveMaintenance;

struct Delta;

enum class DeltaPayload : uint8_t {
  NONE = 0,
  ApplyMaintenance = 1,
  RemoveMaintenance = 2,
  MIN = NONE,
  MAX = RemoveMaintenance
};

inline const char **EnumNamesDeltaPayload() {
  static const char *names[] = { "NONE", "ApplyMaintenance", "RemoveMaintenance", nullptr };
  return names;
}

inline const char *EnumNameDeltaPayload(DeltaPayload e) { return EnumNamesDeltaPayload()[static_cast<int>(e)]; }

template<typename T> struct DeltaPayloadTraits {
  static const DeltaPayload enum_value = DeltaPayload::NONE;
};

template<> struct DeltaPayloadTraits<ApplyMaintenance> {
  static const DeltaPayload enum_value = DeltaPayload::ApplyMaintenance;
};

template<> struct DeltaPayloadTraits<RemoveMaintenance> {
  static const DeltaPayload enum_value = DeltaPayload::RemoveMaintenance;
};

inline bool VerifyDeltaPayload(flatbuffers::Verifier &verifier, const void *union_obj, DeltaPayload type);

struct ShardID FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_SHARD_IDX = 4,
    VT_NODE_IDX = 6
  };
  int16_t shard_idx() const { return GetField<int16_t>(VT_SHARD_IDX, 0); }
  int16_t node_idx() const { return GetField<int16_t>(VT_NODE_IDX, 0); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int16_t>(verifier, VT_SHARD_IDX) &&
           VerifyField<int16_t>(verifier, VT_NODE_IDX) &&
           verifier.EndTable();
  }
};

struct ShardIDBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_shard_idx(int16_t shard_idx) { fbb_.AddElement<int16_t>(ShardID::VT_SHARD_IDX, shard_idx, 0); }
  void add_node_idx(int16_t node_idx) { fbb_.AddElement<int16_t>(ShardID::VT_NODE_IDX, node_idx, 0); }
  ShardIDBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  ShardIDBuilder &operator=(const ShardIDBuilder &);
  flatbuffers::Offset<ShardID> Finish() {
    auto o = flatbuffers::Offset<ShardID>(fbb_.EndTable(start_, 2));
    return o;
  }
};

inline flatbuffers::Offset<ShardID> CreateShardID(flatbuffers::FlatBufferBuilder &_fbb,
    int16_t shard_idx = 0,
    int16_t node_idx = 0) {
  ShardIDBuilder builder_(_fbb);
  builder_.add_node_idx(node_idx);
  builder_.add_shard_idx(shard_idx);
  return builder_.Finish();
}

struct ShardMaintenance FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_SHARD_ID = 4,
    VT_TARGET_MAINTENANCE_STATE = 6
  };
  const flatbuffers::Vector<flatbuffers::Offset<ShardID>> *shard_id() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<ShardID>> *>(VT_SHARD_ID); }
  int32_t target_maintenance_state() const { return GetField<int32_t>(VT_TARGET_MAINTENANCE_STATE, 0); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_SHARD_ID) &&
           verifier.Verify(shard_id()) &&
           verifier.VerifyVectorOfTables(shard_id()) &&
           VerifyField<int32_t>(verifier, VT_TARGET_MAINTENANCE_STATE) &&
           verifier.EndTable();
  }
};

struct ShardMaintenanceBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_shard_id(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ShardID>>> shard_id) { fbb_.AddOffset(ShardMaintenance::VT_SHARD_ID, shard_id); }
  void add_target_maintenance_state(int32_t target_maintenance_state) { fbb_.AddElement<int32_t>(ShardMaintenance::VT_TARGET_MAINTENANCE_STATE, target_maintenance_state, 0); }
  ShardMaintenanceBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  ShardMaintenanceBuilder &operator=(const ShardMaintenanceBuilder &);
  flatbuffers::Offset<ShardMaintenance> Finish() {
    auto o = flatbuffers::Offset<ShardMaintenance>(fbb_.EndTable(start_, 2));
    return o;
  }
};

inline flatbuffers::Offset<ShardMaintenance> CreateShardMaintenance(flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ShardID>>> shard_id = 0,
    int32_t target_maintenance_state = 0) {
  ShardMaintenanceBuilder builder_(_fbb);
  builder_.add_target_maintenance_state(target_maintenance_state);
  builder_.add_shard_id(shard_id);
  return builder_.Finish();
}

inline flatbuffers::Offset<ShardMaintenance> CreateShardMaintenanceDirect(flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<ShardID>> *shard_id = nullptr,
    int32_t target_maintenance_state = 0) {
  return CreateShardMaintenance(_fbb, shard_id ? _fbb.CreateVector<flatbuffers::Offset<ShardID>>(*shard_id) : 0, target_maintenance_state);
}

struct SequencerMaintenance FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_NODE_ID = 4,
    VT_TARGET_MAINTENANCE_STATE = 6
  };
  uint32_t node_id() const { return GetField<uint32_t>(VT_NODE_ID, 0); }
  int32_t target_maintenance_state() const { return GetField<int32_t>(VT_TARGET_MAINTENANCE_STATE, 0); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_NODE_ID) &&
           VerifyField<int32_t>(verifier, VT_TARGET_MAINTENANCE_STATE) &&
           verifier.EndTable();
  }
};

struct SequencerMaintenanceBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_node_id(uint32_t node_id) { fbb_.AddElement<uint32_t>(SequencerMaintenance::VT_NODE_ID, node_id, 0); }
  void add_target_maintenance_state(int32_t target_maintenance_state) { fbb_.AddElement<int32_t>(SequencerMaintenance::VT_TARGET_MAINTENANCE_STATE, target_maintenance_state, 0); }
  SequencerMaintenanceBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  SequencerMaintenanceBuilder &operator=(const SequencerMaintenanceBuilder &);
  flatbuffers::Offset<SequencerMaintenance> Finish() {
    auto o = flatbuffers::Offset<SequencerMaintenance>(fbb_.EndTable(start_, 2));
    return o;
  }
};

inline flatbuffers::Offset<SequencerMaintenance> CreateSequencerMaintenance(flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t node_id = 0,
    int32_t target_maintenance_state = 0) {
  SequencerMaintenanceBuilder builder_(_fbb);
  builder_.add_target_maintenance_state(target_maintenance_state);
  builder_.add_node_id(node_id);
  return builder_.Finish();
}

struct ExtraAttr FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_KEY = 4,
    VT_VALUE = 6
  };
  const flatbuffers::String *key() const { return GetPointer<const flatbuffers::String *>(VT_KEY); }
  bool KeyCompareLessThan(const ExtraAttr *o) const { return *key() < *o->key(); }
  int KeyCompareWithValue(const char *val) const { return strcmp(key()->c_str(), val); }
  const flatbuffers::String *value() const { return GetPointer<const flatbuffers::String *>(VT_VALUE); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyFieldRequired<flatbuffers::uoffset_t>(verifier, VT_KEY) &&
           verifier.Verify(key()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_VALUE) &&
           verifier.Verify(value()) &&
           verifier.EndTable();
  }
};

struct ExtraAttrBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_key(flatbuffers::Offset<flatbuffers::String> key) { fbb_.AddOffset(ExtraAttr::VT_KEY, key); }
  void add_value(flatbuffers::Offset<flatbuffers::String> value) { fbb_.AddOffset(ExtraAttr::VT_VALUE, value); }
  ExtraAttrBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  ExtraAttrBuilder &operator=(const ExtraAttrBuilder &);
  flatbuffers::Offset<ExtraAttr> Finish() {
    auto o = flatbuffers::Offset<ExtraAttr>(fbb_.EndTable(start_, 2));
    fbb_.Required(o, ExtraAttr::VT_KEY);  // key
    return o;
  }
};

inline flatbuffers::Offset<ExtraAttr> CreateExtraAttr(flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> key = 0,
    flatbuffers::Offset<flatbuffers::String> value = 0) {
  ExtraAttrBuilder builder_(_fbb);
  builder_.add_value(value);
  builder_.add_key(key);
  return builder_.Finish();
}

inline flatbuffers::Offset<ExtraAttr> CreateExtraAttrDirect(flatbuffers::FlatBufferBuilder &_fbb,
    const char *key = nullptr,
    const char *value = nullptr) {
  return CreateExtraAttr(_fbb, key ? _fbb.CreateString(key) : 0, value ? _fbb.CreateString(value) : 0);
}

struct MaintenanceHeader FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_USER_ID = 4,
    VT_REASON = 6,
    VT_TYPE = 8,
    VT_FLAGS = 10,
    VT_CREATED_ON = 12,
    VT_EXTRAS = 14
  };
  const flatbuffers::String *user_id() const { return GetPointer<const flatbuffers::String *>(VT_USER_ID); }
  const flatbuffers::String *reason() const { return GetPointer<const flatbuffers::String *>(VT_REASON); }
  uint16_t type() const { return GetField<uint16_t>(VT_TYPE, 0); }
  uint16_t flags() const { return GetField<uint16_t>(VT_FLAGS, 0); }
  uint64_t created_on() const { return GetField<uint64_t>(VT_CREATED_ON, 0); }
  const flatbuffers::Vector<flatbuffers::Offset<ExtraAttr>> *extras() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<ExtraAttr>> *>(VT_EXTRAS); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_USER_ID) &&
           verifier.Verify(user_id()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_REASON) &&
           verifier.Verify(reason()) &&
           VerifyField<uint16_t>(verifier, VT_TYPE) &&
           VerifyField<uint16_t>(verifier, VT_FLAGS) &&
           VerifyField<uint64_t>(verifier, VT_CREATED_ON) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_EXTRAS) &&
           verifier.Verify(extras()) &&
           verifier.VerifyVectorOfTables(extras()) &&
           verifier.EndTable();
  }
};

struct MaintenanceHeaderBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_user_id(flatbuffers::Offset<flatbuffers::String> user_id) { fbb_.AddOffset(MaintenanceHeader::VT_USER_ID, user_id); }
  void add_reason(flatbuffers::Offset<flatbuffers::String> reason) { fbb_.AddOffset(MaintenanceHeader::VT_REASON, reason); }
  void add_type(uint16_t type) { fbb_.AddElement<uint16_t>(MaintenanceHeader::VT_TYPE, type, 0); }
  void add_flags(uint16_t flags) { fbb_.AddElement<uint16_t>(MaintenanceHeader::VT_FLAGS, flags, 0); }
  void add_created_on(uint64_t created_on) { fbb_.AddElement<uint64_t>(MaintenanceHeader::VT_CREATED_ON, created_on, 0); }
  void add_extras(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ExtraAttr>>> extras) { fbb_.AddOffset(MaintenanceHeader::VT_EXTRAS, extras); }
  MaintenanceHeaderBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  MaintenanceHeaderBuilder &operator=(const MaintenanceHeaderBuilder &);
  flatbuffers::Offset<MaintenanceHeader> Finish() {
    auto o = flatbuffers::Offset<MaintenanceHeader>(fbb_.EndTable(start_, 6));
    return o;
  }
};

inline flatbuffers::Offset<MaintenanceHeader> CreateMaintenanceHeader(flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> user_id = 0,
    flatbuffers::Offset<flatbuffers::String> reason = 0,
    uint16_t type = 0,
    uint16_t flags = 0,
    uint64_t created_on = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ExtraAttr>>> extras = 0) {
  MaintenanceHeaderBuilder builder_(_fbb);
  builder_.add_created_on(created_on);
  builder_.add_extras(extras);
  builder_.add_reason(reason);
  builder_.add_user_id(user_id);
  builder_.add_flags(flags);
  builder_.add_type(type);
  return builder_.Finish();
}

inline flatbuffers::Offset<MaintenanceHeader> CreateMaintenanceHeaderDirect(flatbuffers::FlatBufferBuilder &_fbb,
    const char *user_id = nullptr,
    const char *reason = nullptr,
    uint16_t type = 0,
    uint16_t flags = 0,
    uint64_t created_on = 0,
    const std::vector<flatbuffers::Offset<ExtraAttr>> *extras = nullptr) {
  return CreateMaintenanceHeader(_fbb, user_id ? _fbb.CreateString(user_id) : 0, reason ? _fbb.CreateString(reason) : 0, type, flags, created_on, extras ? _fbb.CreateVector<flatbuffers::Offset<ExtraAttr>>(*extras) : 0);
}

struct ApplyMaintenance FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_SEQUENCER_MAINTENANCE = 4,
    VT_SHARD_MAINTENANCE = 6
  };
  const flatbuffers::Vector<flatbuffers::Offset<SequencerMaintenance>> *sequencer_maintenance() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<SequencerMaintenance>> *>(VT_SEQUENCER_MAINTENANCE); }
  const flatbuffers::Vector<flatbuffers::Offset<ShardMaintenance>> *shard_maintenance() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<ShardMaintenance>> *>(VT_SHARD_MAINTENANCE); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_SEQUENCER_MAINTENANCE) &&
           verifier.Verify(sequencer_maintenance()) &&
           verifier.VerifyVectorOfTables(sequencer_maintenance()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_SHARD_MAINTENANCE) &&
           verifier.Verify(shard_maintenance()) &&
           verifier.VerifyVectorOfTables(shard_maintenance()) &&
           verifier.EndTable();
  }
};

struct ApplyMaintenanceBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_sequencer_maintenance(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SequencerMaintenance>>> sequencer_maintenance) { fbb_.AddOffset(ApplyMaintenance::VT_SEQUENCER_MAINTENANCE, sequencer_maintenance); }
  void add_shard_maintenance(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ShardMaintenance>>> shard_maintenance) { fbb_.AddOffset(ApplyMaintenance::VT_SHARD_MAINTENANCE, shard_maintenance); }
  ApplyMaintenanceBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  ApplyMaintenanceBuilder &operator=(const ApplyMaintenanceBuilder &);
  flatbuffers::Offset<ApplyMaintenance> Finish() {
    auto o = flatbuffers::Offset<ApplyMaintenance>(fbb_.EndTable(start_, 2));
    return o;
  }
};

inline flatbuffers::Offset<ApplyMaintenance> CreateApplyMaintenance(flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SequencerMaintenance>>> sequencer_maintenance = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ShardMaintenance>>> shard_maintenance = 0) {
  ApplyMaintenanceBuilder builder_(_fbb);
  builder_.add_shard_maintenance(shard_maintenance);
  builder_.add_sequencer_maintenance(sequencer_maintenance);
  return builder_.Finish();
}

inline flatbuffers::Offset<ApplyMaintenance> CreateApplyMaintenanceDirect(flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<SequencerMaintenance>> *sequencer_maintenance = nullptr,
    const std::vector<flatbuffers::Offset<ShardMaintenance>> *shard_maintenance = nullptr) {
  return CreateApplyMaintenance(_fbb, sequencer_maintenance ? _fbb.CreateVector<flatbuffers::Offset<SequencerMaintenance>>(*sequencer_maintenance) : 0, shard_maintenance ? _fbb.CreateVector<flatbuffers::Offset<ShardMaintenance>>(*shard_maintenance) : 0);
}

struct RemoveMaintenance FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_SHARDS = 4,
    VT_SEQUENCER_NODES = 6
  };
  const flatbuffers::Vector<flatbuffers::Offset<ShardID>> *shards() const { return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<ShardID>> *>(VT_SHARDS); }
  const flatbuffers::Vector<uint32_t> *sequencer_nodes() const { return GetPointer<const flatbuffers::Vector<uint32_t> *>(VT_SEQUENCER_NODES); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_SHARDS) &&
           verifier.Verify(shards()) &&
           verifier.VerifyVectorOfTables(shards()) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_SEQUENCER_NODES) &&
           verifier.Verify(sequencer_nodes()) &&
           verifier.EndTable();
  }
};

struct RemoveMaintenanceBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_shards(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ShardID>>> shards) { fbb_.AddOffset(RemoveMaintenance::VT_SHARDS, shards); }
  void add_sequencer_nodes(flatbuffers::Offset<flatbuffers::Vector<uint32_t>> sequencer_nodes) { fbb_.AddOffset(RemoveMaintenance::VT_SEQUENCER_NODES, sequencer_nodes); }
  RemoveMaintenanceBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  RemoveMaintenanceBuilder &operator=(const RemoveMaintenanceBuilder &);
  flatbuffers::Offset<RemoveMaintenance> Finish() {
    auto o = flatbuffers::Offset<RemoveMaintenance>(fbb_.EndTable(start_, 2));
    return o;
  }
};

inline flatbuffers::Offset<RemoveMaintenance> CreateRemoveMaintenance(flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<ShardID>>> shards = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint32_t>> sequencer_nodes = 0) {
  RemoveMaintenanceBuilder builder_(_fbb);
  builder_.add_sequencer_nodes(sequencer_nodes);
  builder_.add_shards(shards);
  return builder_.Finish();
}

inline flatbuffers::Offset<RemoveMaintenance> CreateRemoveMaintenanceDirect(flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<ShardID>> *shards = nullptr,
    const std::vector<uint32_t> *sequencer_nodes = nullptr) {
  return CreateRemoveMaintenance(_fbb, shards ? _fbb.CreateVector<flatbuffers::Offset<ShardID>>(*shards) : 0, sequencer_nodes ? _fbb.CreateVector<uint32_t>(*sequencer_nodes) : 0);
}

struct Delta FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_HEADER = 4,
    VT_PAYLOAD_TYPE = 6,
    VT_PAYLOAD = 8
  };
  const MaintenanceHeader *header() const { return GetPointer<const MaintenanceHeader *>(VT_HEADER); }
  DeltaPayload payload_type() const { return static_cast<DeltaPayload>(GetField<uint8_t>(VT_PAYLOAD_TYPE, 0)); }
  const void *payload() const { return GetPointer<const void *>(VT_PAYLOAD); }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_HEADER) &&
           verifier.VerifyTable(header()) &&
           VerifyField<uint8_t>(verifier, VT_PAYLOAD_TYPE) &&
           VerifyField<flatbuffers::uoffset_t>(verifier, VT_PAYLOAD) &&
           VerifyDeltaPayload(verifier, payload(), payload_type()) &&
           verifier.EndTable();
  }
};

struct DeltaBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_header(flatbuffers::Offset<MaintenanceHeader> header) { fbb_.AddOffset(Delta::VT_HEADER, header); }
  void add_payload_type(DeltaPayload payload_type) { fbb_.AddElement<uint8_t>(Delta::VT_PAYLOAD_TYPE, static_cast<uint8_t>(payload_type), 0); }
  void add_payload(flatbuffers::Offset<void> payload) { fbb_.AddOffset(Delta::VT_PAYLOAD, payload); }
  DeltaBuilder(flatbuffers::FlatBufferBuilder &_fbb) : fbb_(_fbb) { start_ = fbb_.StartTable(); }
  DeltaBuilder &operator=(const DeltaBuilder &);
  flatbuffers::Offset<Delta> Finish() {
    auto o = flatbuffers::Offset<Delta>(fbb_.EndTable(start_, 3));
    return o;
  }
};

inline flatbuffers::Offset<Delta> CreateDelta(flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<MaintenanceHeader> header = 0,
    DeltaPayload payload_type = DeltaPayload::NONE,
    flatbuffers::Offset<void> payload = 0) {
  DeltaBuilder builder_(_fbb);
  builder_.add_payload(payload);
  builder_.add_header(header);
  builder_.add_payload_type(payload_type);
  return builder_.Finish();
}

inline bool VerifyDeltaPayload(flatbuffers::Verifier &verifier, const void *union_obj, DeltaPayload type) {
  switch (type) {
    case DeltaPayload::NONE: return true;
    case DeltaPayload::ApplyMaintenance: return verifier.VerifyTable(reinterpret_cast<const ApplyMaintenance *>(union_obj));
    case DeltaPayload::RemoveMaintenance: return verifier.VerifyTable(reinterpret_cast<const RemoveMaintenance *>(union_obj));
    default: return false;
  }
}

inline const facebook::logdevice::cluster_maintenance_log_record::fbuffers::Delta *GetDelta(const void *buf) {
  return flatbuffers::GetRoot<facebook::logdevice::cluster_maintenance_log_record::fbuffers::Delta>(buf);
}

inline bool VerifyDeltaBuffer(flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<facebook::logdevice::cluster_maintenance_log_record::fbuffers::Delta>(nullptr);
}

inline void FinishDeltaBuffer(flatbuffers::FlatBufferBuilder &fbb, flatbuffers::Offset<facebook::logdevice::cluster_maintenance_log_record::fbuffers::Delta> root) {
  fbb.Finish(root);
}

}  // namespace fbuffers
}  // namespace cluster_maintenance_log_record
}  // namespace logdevice
}  // namespace facebook

#endif  // FLATBUFFERS_GENERATED_CLUSTERMAINTENANCELOGRECORD_FACEBOOK_LOGDEVICE_CLUSTER_MAINTENANCE_LOG_RECORD_FBUFFERS_H_
