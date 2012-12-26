#ifndef EVENTWRAPPER_H
#define EVENTWRAPPER_H

#include "Event.h"
#include "boost/scoped_ptr.hpp"

namespace Robomongo
{
    class EventWrapper : public QEvent
    {
    public:
        EventWrapper(Event *event, QList<QObject *> receivers) :
            QEvent(event->type()),
            _event(event),
            _receivers(receivers) {}

        Event *event() const { return _event.get(); }
        QList<QObject *> receivers() const { return _receivers; }

    private:
        boost::scoped_ptr<Event> _event;
        QList<QObject *> _receivers;
    };
}


#endif // EVENTWRAPPER_H