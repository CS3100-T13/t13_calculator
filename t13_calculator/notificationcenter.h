#ifndef NOTIFICATIONCENTER_H
#define NOTIFICATIONCENTER_H

#include <unordered_map>
#include <vector>

#include "notificationsubscriber.h"

/* Types **********************************************************************/

typedef std::unordered_map<
  NotificationID,
  std::vector< NotificationSubscriber *> *
> notification_map;

/* Class Declaration **********************************************************/

class NotificationCenter {
private:
   notification_map m_notifications;

public:
  NotificationCenter();

  ~NotificationCenter();

  void subscribe(
    const NotificationID notification,
    NotificationSubscriber *subscriber
  );

  bool unsubscribe(
    const NotificationID notification,
    NotificationSubscriber *unsubscriber
  );

  bool post( const NotificationID notification );
};

#endif // NOTIFICATIONCENTER_H
