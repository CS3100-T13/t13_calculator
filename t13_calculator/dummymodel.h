#ifndef DUMMYMODEL_H
#define DUMMYMODEL_H

#include <QString>

#include "notificationcenter.h"

#define STRING_UPDATED "STRING_UPDATED"

class DummyModel {
private:
  NotificationCenter *const m_nc;
  QString m_str;
  size_t m_size;
  char m_char;

  void updateString();

public:
  DummyModel();

  ~DummyModel();

  NotificationCenter *getNotificationCenter() const;

  QString getString() const;

  void updateSize( const size_t newSize );

  void updateChar( const char newChar );

};

#endif // DUMMYMODEL_H
