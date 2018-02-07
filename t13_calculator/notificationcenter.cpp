#include "notificationcenter.h"

using namespace std;


/* Constructor ****************************************************************/


NotificationCenter::NotificationCenter()
  : m_notifications()
{}


/* Descructor *****************************************************************/


NotificationCenter::~NotificationCenter() {

  /* Local variables */
  notification_map::const_iterator it;

  /* For each notification identifier */
  for( it = m_notifications.begin(); it != m_notifications.end(); ++it ) {

    /* Deallocate the corresponding vector */
    delete ( it->second );
  }
}


/* Member Functions ***********************************************************/


void NotificationCenter::subscribe(
  const NotificationID notification,
  NotificationSubscriber *subscriber
    ) {

  /* Local variables */
  notification_map::const_iterator it;
  vector< NotificationSubscriber *> *subscribers;

  /* Get reference to specied notification */
  it = m_notifications.find( notification );

  /* If notification doesn't exist */
  if( it == m_notifications.end() ) {

    /* Create it */
    m_notifications[ notification ] = new vector< NotificationSubscriber *>();
  }

  /* Add subscriber to list of current subscribers */
  subscribers = m_notifications[ notification ];
  subscribers->push_back( subscriber );
}


bool NotificationCenter::unsubscribe(
  const NotificationID notification,
  NotificationSubscriber *unsubscriber
    ) {

  /* Local variables */
  notification_map::const_iterator it;
  vector< NotificationSubscriber *> *subscribers;

  /* Get reference to specied notification */
  it = m_notifications.find( notification );

  /* If notification doesn't exist */
  if( it == m_notifications.end() ) {

    /* Indicate unsubsciber was not currently subscribed to this notification */
    return false;
  }

  /* For each of the current subscribers */
  subscribers = m_notifications[ notification ];
  for( size_t i = 0; i < subscribers->size(); ++i ) {

    /* If this is the unsubscriber */
    if( unsubscriber == subscribers->at( i ) ) {

      /* Remove this subscriber from list */
      subscribers->erase( subscribers->begin() + i );
      return true;
    }
  }

  /* Indicate unsubsciber was not currently subscribed to this notification */
  return false;
}


bool NotificationCenter::post( const NotificationID notification ) {

  /* Local variables */
  notification_map::const_iterator it;
  vector< NotificationSubscriber *> *subscribers;

  /* Get reference to specied notification */
  it = m_notifications.find( notification );

  /* If notification doesn't exist */
  if( it == m_notifications.end() ) {

    /* Indicate no subscribers for this notification */
    return false;
  }

  /* For each of the current subscribers */
  subscribers = m_notifications[ notification ];
  for( size_t i = 0; i < subscribers->size(); ++i ) {
    subscribers->at( i )->notificationRecieved( notification );
  }

  return true;
}
