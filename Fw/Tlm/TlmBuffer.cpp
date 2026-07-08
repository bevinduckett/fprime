#include <Fw/Tlm/TlmBuffer.hpp>
#include <Fw/Types/Assert.hpp>

namespace Fw {

TlmBuffer::TlmBuffer(const U8* args, FwSizeType size) {
    this->m_buffAddr = this->m_bufferData;
    this->m_capacity = sizeof(this->m_bufferData);
    SerializeStatus stat = LinearBufferBase::setBuff(args, size);
    FW_ASSERT(FW_SERIALIZE_OK == stat, static_cast<FwAssertArgType>(stat));
}

TlmBuffer::TlmBuffer() {
    this->m_buffAddr = this->m_bufferData;
    this->m_capacity = sizeof(this->m_bufferData);
}

TlmBuffer::~TlmBuffer() {}

TlmBuffer::TlmBuffer(const TlmBuffer& other) : Fw::LinearBufferBase() {
    this->m_buffAddr = this->m_bufferData;
    this->m_capacity = sizeof(this->m_bufferData);
    SerializeStatus stat = LinearBufferBase::setBuff(other.m_bufferData, other.m_serLoc);
    FW_ASSERT(FW_SERIALIZE_OK == stat, static_cast<FwAssertArgType>(stat));
}

TlmBuffer& TlmBuffer::operator=(const TlmBuffer& other) {
    if (this == &other) {
        return *this;
    }

    SerializeStatus stat = LinearBufferBase::setBuff(other.m_bufferData, other.m_serLoc);
    FW_ASSERT(FW_SERIALIZE_OK == stat, static_cast<FwAssertArgType>(stat));
    return *this;
}

FwSizeType TlmBuffer::getBuffCapacity() const {
    return this->getCapacity();
}

}  // namespace Fw
