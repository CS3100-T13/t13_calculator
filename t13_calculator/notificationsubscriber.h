#ifndef NOTIFICATIONSUBSCRIBER_H
#define NOTIFICATIONSUBSCRIBER_H

#include <string>

typedef std::string NotificationID;

class NotificationSubscriber {
public:

  virtual void notificationRecieved( const NotificationID notificationName ) = 0;

};

#endif // NOTIFICATIONSUBSCRIBER_H
