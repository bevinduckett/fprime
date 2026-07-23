/*
 * TlmBuffer.hpp
 *
 *      Author: tcanham
 */

/*
 * Description:
 * This object contains the TlmBuffer type, used for storing telemetry
 */
#ifndef FW_TLM_BUFFER_HPP
#define FW_TLM_BUFFER_HPP

#include <Fw/FPrimeBasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>

#if defined(__GNUC__) || defined(__clang__)
#define ALWAYS_INLINE __attribute__((always_inline))
#else
#define ALWAYS_INLINE
#endif

namespace Fw {

class TlmBuffer final : public LinearBufferBase {
  public:
    enum { SERIALIZED_SIZE = STATIC_SERIALIZED_SIZE(FW_TLM_BUFFER_MAX_SIZE) };

    TlmBuffer(const U8* args, FwSizeType size);
    TlmBuffer();
    TlmBuffer(const TlmBuffer& other);
    virtual ~TlmBuffer();
    TlmBuffer& operator=(const TlmBuffer& other);

    DEPRECATED(FwSizeType getBuffCapacity() const, "Use getCapacity() instead");

    ALWAYS_INLINE inline FwSizeType getCapacity() const override {  // !< returns capacity, not current size, of buffer
        return sizeof(this->m_bufferData);
    }

    ALWAYS_INLINE inline U8* getBuffAddr() override { return this->m_bufferData; }

    ALWAYS_INLINE inline const U8* getBuffAddr() const override { return this->m_bufferData; }

  private:
    U8 m_bufferData[FW_TLM_BUFFER_MAX_SIZE];  // command argument buffer
};

}  // namespace Fw

#endif
