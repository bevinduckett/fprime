#include <Fw/Cmd/CmdArgBuffer.hpp>
#include <Fw/Types/Assert.hpp>

namespace Fw {

CmdArgBuffer::CmdArgBuffer(const U8* args, FwSizeType size) {
    this->m_buffAddr = this->m_bufferData;
    this->m_capacity = sizeof(this->m_bufferData);
    SerializeStatus stat = this->setBuff(args, size);
    FW_ASSERT(FW_SERIALIZE_OK == stat, static_cast<FwAssertArgType>(stat));
}

CmdArgBuffer::CmdArgBuffer() {
    this->m_buffAddr = this->m_bufferData;
    this->m_capacity = sizeof(this->m_bufferData);
}

CmdArgBuffer::~CmdArgBuffer() {}

CmdArgBuffer::CmdArgBuffer(const CmdArgBuffer& other) : Fw::LinearBufferBase() {
    this->m_buffAddr = this->m_bufferData;
    this->m_capacity = sizeof(this->m_bufferData);
    SerializeStatus stat = this->setBuff(other.m_bufferData, other.m_serLoc);
    FW_ASSERT(FW_SERIALIZE_OK == stat, static_cast<FwAssertArgType>(stat));
}

CmdArgBuffer& CmdArgBuffer::operator=(const CmdArgBuffer& other) {
    if (this == &other) {
        return *this;
    }

    SerializeStatus stat = this->setBuff(other.m_bufferData, other.m_serLoc);
    FW_ASSERT(FW_SERIALIZE_OK == stat, static_cast<FwAssertArgType>(stat));
    return *this;
}

FwSizeType CmdArgBuffer::getBuffCapacity() const {
    return this->getCapacity();
}

}  // namespace Fw
