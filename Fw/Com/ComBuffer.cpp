#include <Fw/Com/ComBuffer.hpp>
#include <Fw/Types/Assert.hpp>

namespace Fw {

ComBuffer::ComBuffer(const U8* args, FwSizeType size) {
    this->m_buffAddr = this->m_bufferData;
    this->m_capacity = sizeof(this->m_bufferData);
    SerializeStatus stat = LinearBufferBase::setBuff(args, size);
    FW_ASSERT(FW_SERIALIZE_OK == stat, static_cast<FwAssertArgType>(stat));
}

ComBuffer::ComBuffer() {
    this->m_buffAddr = this->m_bufferData;
    this->m_capacity = sizeof(this->m_bufferData);
}

ComBuffer::~ComBuffer() {}

ComBuffer::ComBuffer(const ComBuffer& other) : Fw::LinearBufferBase() {
    this->m_buffAddr = this->m_bufferData;
    this->m_capacity = sizeof(this->m_bufferData);
    SerializeStatus stat = LinearBufferBase::setBuff(other.m_bufferData, other.m_serLoc);
    FW_ASSERT(FW_SERIALIZE_OK == stat, static_cast<FwAssertArgType>(stat));
}

ComBuffer& ComBuffer::operator=(const ComBuffer& other) {
    if (this == &other) {
        return *this;
    }

    SerializeStatus stat = LinearBufferBase::setBuff(other.m_bufferData, other.m_serLoc);
    FW_ASSERT(FW_SERIALIZE_OK == stat, static_cast<FwAssertArgType>(stat));
    return *this;
}

FwSizeType ComBuffer::getBuffCapacity() const {
    return this->getCapacity();
}

}  // namespace Fw
