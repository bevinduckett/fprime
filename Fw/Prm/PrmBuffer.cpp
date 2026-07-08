#include <Fw/Prm/PrmBuffer.hpp>
#include <Fw/Types/Assert.hpp>

namespace Fw {

ParamBuffer::ParamBuffer(const U8* args, FwSizeType size) {
    this->m_buffAddr = this->m_bufferData;
    this->m_capacity = sizeof(this->m_bufferData);
    SerializeStatus stat = LinearBufferBase::setBuff(args, size);
    FW_ASSERT(FW_SERIALIZE_OK == stat, static_cast<FwAssertArgType>(stat));
}

ParamBuffer::ParamBuffer() {
    this->m_buffAddr = this->m_bufferData;
    this->m_capacity = sizeof(this->m_bufferData);
}

ParamBuffer::~ParamBuffer() {}

ParamBuffer::ParamBuffer(const ParamBuffer& other) : Fw::LinearBufferBase() {
    this->m_buffAddr = this->m_bufferData;
    this->m_capacity = sizeof(this->m_bufferData);
    SerializeStatus stat = LinearBufferBase::setBuff(other.m_bufferData, other.m_serLoc);
    FW_ASSERT(FW_SERIALIZE_OK == stat, static_cast<FwAssertArgType>(stat));
}

ParamBuffer& ParamBuffer::operator=(const ParamBuffer& other) {
    if (this == &other) {
        return *this;
    }

    SerializeStatus stat = LinearBufferBase::setBuff(other.m_bufferData, other.m_serLoc);
    FW_ASSERT(FW_SERIALIZE_OK == stat, static_cast<FwAssertArgType>(stat));
    return *this;
}

FwSizeType ParamBuffer::getBuffCapacity() const {
    return this->getCapacity();
}

}  // namespace Fw
