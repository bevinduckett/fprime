#include <Fw/Sm/SmSignalBuffer.hpp>
#include <Fw/Types/Assert.hpp>

namespace Fw {

SmSignalBuffer::SmSignalBuffer(const U8* args, Serializable::SizeType size) : m_bufferData{} {
    this->m_buffAddr = this->m_bufferData;
    this->m_capacity = sizeof(this->m_bufferData);
    FW_ASSERT(args != nullptr);
    FW_ASSERT(size <= sizeof(this->m_bufferData));
    SerializeStatus stat = LinearBufferBase::setBuff(args, size);
    FW_ASSERT(FW_SERIALIZE_OK == stat, static_cast<FwAssertArgType>(stat));
}

SmSignalBuffer::SmSignalBuffer() : m_bufferData{} {
    this->m_buffAddr = this->m_bufferData;
    this->m_capacity = sizeof(this->m_bufferData);
}

SmSignalBuffer::~SmSignalBuffer() {}

SmSignalBuffer::SmSignalBuffer(const SmSignalBuffer& other) : Fw::LinearBufferBase(), m_bufferData{} {
    this->m_buffAddr = this->m_bufferData;
    this->m_capacity = sizeof(this->m_bufferData);
    FW_ASSERT(other.getBuffAddr() != nullptr);
    FW_ASSERT(other.m_serLoc <= sizeof(this->m_bufferData));

    SerializeStatus stat = LinearBufferBase::setBuff(other.m_bufferData, other.m_serLoc);
    FW_ASSERT(FW_SERIALIZE_OK == stat, static_cast<FwAssertArgType>(stat));
}

SmSignalBuffer& SmSignalBuffer::operator=(const SmSignalBuffer& other) {
    if (this == &other) {
        return *this;
    }

    FW_ASSERT(other.getBuffAddr() != nullptr);
    FW_ASSERT(other.m_serLoc <= sizeof(this->m_bufferData));

    SerializeStatus stat = LinearBufferBase::setBuff(other.m_bufferData, other.m_serLoc);
    FW_ASSERT(FW_SERIALIZE_OK == stat, static_cast<FwAssertArgType>(stat));
    return *this;
}

Serializable::SizeType SmSignalBuffer::getBuffCapacity() const {
    return this->getCapacity();
}

}  // namespace Fw
