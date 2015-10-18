#ifndef NDSPVVARIABLEIN_H
#define NDSPVVARIABLEIN_H

#include "definitions.h"
#include "pvBaseIn.h"

namespace nds
{

/**
 * @brief An input PV object that also stores the value so it does not need to
 *        delegate the read function.
 *
 * The device support can use PVVariableIn::setValue() to modify the PV's value;
 * the read() method will be used to read the value on the control system side.
 *
 */
template <typename T>
class NDS3_API PVVariableIn: public PVBaseIn
{
public:

    PVVariableIn();

    /**
     * @brief Construct the PVVariableIn object.
     *
     * @param name          name of the PV
     */
    PVVariableIn(const std::string& name);

    /**
     * @ingroup datareadwrite
     * @brief Set the variable's value.
     *
     * The control system will retrieve the value when it choses to do so.
     *
     * If one or more output PVs have been suscribed to this PV via Factory::subscribe()
     * then the value will be pushed immediately to all the subscribed PVs via PVBaseOut::write().
     *
     * See also Factory::subscribe() and PVBaseOut::subscribeTo().
     *
     * @param value the value to write into the variable. The timestamp will
     *              be taken via the getTimestamp() method.
     */
    void setValue(const T& value);

    /**
     * @ingroup datareadwrite
     * @brief Set the variable's value.
     *
     * The control system will retrieve the value when it choses to do so.
     *
     * If one or more output PVs have been suscribed to this PV via Factory::subscribe()
     * then the value will be pushed immediately to all the subscribed PVs via PVBaseOut::write().
     *
     * See also Factory::subscribe() and PVBaseOut::subscribeTo().
     *
     * @param timestamp the timestamp to assign to the variable
     * @param value     the value to write into the variable
     */
    void setValue(const timespec& timestamp, const T& value);
};

}

#endif // NDSPVVARIABLEIN_H
