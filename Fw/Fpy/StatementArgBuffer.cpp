#include <Fw/Fpy/StatementArgBuffer.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/StringBase.hpp>

namespace Fw {

StatementArgBuffer::StatementArgBuffer(const U8* args, FwSizeType size) {
    this->m_buffAddr = this->m_bufferData;
    this->m_capacity = sizeof(this->m_bufferData);
    SerializeStatus stat = LinearBufferBase::setBuff(args, size);
    FW_ASSERT(FW_SERIALIZE_OK == stat, static_cast<FwAssertArgType>(stat));
}

StatementArgBuffer::StatementArgBuffer() {
    this->m_buffAddr = this->m_bufferData;
    this->m_capacity = sizeof(this->m_bufferData);
}

StatementArgBuffer::~StatementArgBuffer() {}

StatementArgBuffer::StatementArgBuffer(const StatementArgBuffer& other) : Fw::LinearBufferBase() {
    this->m_buffAddr = this->m_bufferData;
    this->m_capacity = sizeof(this->m_bufferData);
    SerializeStatus stat = LinearBufferBase::setBuff(other.m_bufferData, other.m_serLoc);
    FW_ASSERT(FW_SERIALIZE_OK == stat, static_cast<FwAssertArgType>(stat));
}

StatementArgBuffer& StatementArgBuffer::operator=(const StatementArgBuffer& other) {
    if (this == &other) {
        return *this;
    }

    SerializeStatus stat = LinearBufferBase::setBuff(other.m_bufferData, other.m_serLoc);
    FW_ASSERT(FW_SERIALIZE_OK == stat, static_cast<FwAssertArgType>(stat));
    return *this;
}

Serializable::SizeType StatementArgBuffer::getBuffCapacity() const {
    return this->getCapacity();
}

bool StatementArgBuffer::operator==(const StatementArgBuffer& other) const {
    if (this->getSize() != other.m_serLoc) {
        return false;
    }

    const U8* us = this->getBuffAddr();
    const U8* them = other.getBuffAddr();

    FW_ASSERT(us);
    FW_ASSERT(them);

    for (Serializable::SizeType byte = 0; byte < this->getSize(); byte++) {
        if (us[byte] != them[byte]) {
            return false;
        }
    }

    return true;
}

#if FW_SERIALIZABLE_TO_STRING
void StatementArgBuffer::toString(Fw::StringBase& text) const {
    static const char* formatString = "(data = %p, size = %" PRI_FwSizeType ")";
    text.format(formatString, &this->m_bufferData, this->getSize());
}
#endif
}  // namespace Fw
