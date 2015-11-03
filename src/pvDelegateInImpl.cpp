#include "../include/nds3impl/pvDelegateInImpl.h"
#include <type_traits>
namespace nds
{

/*
 * Constructor
 *
 *************/
template <typename T>
PVDelegateInImpl<T>::PVDelegateInImpl(const std::string& name, read_t readFunction): PVBaseInImpl(name),
    m_reader(readFunction)
{}


/*
 * Called when the control system wants to read data
 *
 ***************************************************/
template <typename T>
void PVDelegateInImpl<T>::read(timespec* pTimestamp, T* pValue) const
{
    m_reader(pTimestamp, pValue);
}


/*
 * Returns the data type
 *
 ***********************/
template <typename T>
dataType_t PVDelegateInImpl<T>::getDataType() const
{
    return getDataTypeForCPPType<T>();
}


// Instantiate all the needed data types
////////////////////////////////////////
template class PVDelegateInImpl<std::int32_t>;
template class PVDelegateInImpl<double>;
template class PVDelegateInImpl<std::vector<std::int8_t> >;
template class PVDelegateInImpl<std::vector<std::uint8_t> >;
template class PVDelegateInImpl<std::vector<std::int32_t> >;
template class PVDelegateInImpl<std::vector<double> >;
template class PVDelegateInImpl<std::string>;

}


