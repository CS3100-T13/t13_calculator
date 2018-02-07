#include "dummymodel.h"

DummyModel::DummyModel() :
  m_nc( new NotificationCenter() ),
  m_str(),
  m_size( 1 ),
  m_char( '*' ) {

  /* Initialize string */
  updateString();
}


DummyModel::~DummyModel() {
  delete m_nc;
}


void DummyModel::updateString() {

  /* Temp c string variable */
  char *c_str = new char[ m_size + 1 ];

  /* Initialize c string */
  for( size_t i = 0; i < m_size; i++ ) {
    c_str[ i ] = m_char;
  }
  c_str[ m_size ] = '\0';

  /* Update member variable */
  m_str = QString( c_str );

  /* Deallocate temp variable */
  delete c_str;
}


NotificationCenter *DummyModel::getNotificationCenter() const {
  return m_nc;
}

QString DummyModel::getString() const {
  return m_str;
}

void DummyModel::updateSize( const size_t newSize ) {

  /* Update member variable */
  m_size = newSize;

  /* Recalculate string */
  updateString();

  /* Send update notification */
  m_nc->post( STRING_UPDATED );
}

void DummyModel::updateChar( const char newChar ) {

  /* Update member variable */
  m_char = newChar;

  /* Recalculate string */
  updateString();

  /* Send update notification */
  m_nc->post( STRING_UPDATED );
}
