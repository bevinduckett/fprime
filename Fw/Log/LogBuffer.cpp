#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Types/Assert.hpp>

namespace Fw {

LogBuffer::LogBuffer(const U8* args, FwSizeType size) {
    this->m_buffAddr = this->m_bufferData;
    this->m_capacity = sizeof(this->m_bufferData);
    SerializeStatus stat = LinearBufferBase::setBuff(args, size);
    FW_ASSERT(FW_SERIALIZE_OK == stat, static_cast<FwAssertArgType>(stat));
}

LogBuffer::LogBuffer() {
    this->m_buffAddr = this->m_bufferData;
    this->m_capacity = sizeof(this->m_bufferData);
}

LogBuffer::~LogBuffer() {}

LogBuffer::LogBuffer(const LogBuffer& other) : Fw::LinearBufferBase() {
    this->m_buffAddr = this->m_bufferData;
    this->m_capacity = sizeof(this->m_bufferData);
    SerializeStatus stat = LinearBufferBase::setBuff(other.m_bufferData, other.m_serLoc);
    FW_ASSERT(FW_SERIALIZE_OK == stat, static_cast<FwAssertArgType>(stat));
}

LogBuffer& LogBuffer::operator=(const LogBuffer& other) {
    if (this == &other) {
        return *this;
    }

    SerializeStatus stat = LinearBufferBase::setBuff(other.m_bufferData, other.m_serLoc);
    FW_ASSERT(FW_SERIALIZE_OK == stat, static_cast<FwAssertArgType>(stat));
    return *this;
}

FwSizeType LogBuffer::getBuffCapacity() const {
    return this->getCapacity();
}

}  // namespace Fw
