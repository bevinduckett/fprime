// ======================================================================
// @file   ComBuffer.hpp
// @author F Prime
// @brief  A buffer sized for communication packets
// ======================================================================

#ifndef FW_COM_BUFFER_HPP
#define FW_COM_BUFFER_HPP

#include <cstring>
#include "Fw/Types/LinearBufferTemplate.hpp"

namespace Fw {

class ComBuffer final : public LinearBufferTemplate<FW_COM_BUFFER_MAX_SIZE> {
  public:
    ComBuffer() { std::memset(this->getBuffAddr(), 0, this->getCapacity()); }

    ComBuffer(const U8* args, FwSizeType size) : LinearBufferTemplate<FW_COM_BUFFER_MAX_SIZE>(args, size) {
        const FwSizeType dataSize = this->getSize();
        std::memset(this->getBuffAddr() + dataSize, 0, this->getCapacity() - dataSize);
    }

    ComBuffer(const ComBuffer& other) : LinearBufferTemplate<FW_COM_BUFFER_MAX_SIZE>(other) {
        const FwSizeType dataSize = this->getSize();
        std::memset(this->getBuffAddr() + dataSize, 0, this->getCapacity() - dataSize);
    }

    ComBuffer& operator=(const ComBuffer& other) {
        if (this != &other) {
            LinearBufferTemplate<FW_COM_BUFFER_MAX_SIZE>::operator=(other);
            const FwSizeType dataSize = this->getSize();
            std::memset(this->getBuffAddr() + dataSize, 0, this->getCapacity() - dataSize);
        }
        return *this;
    }

    ~ComBuffer() override = default;
};

}  // namespace Fw

#endif
