#ifndef PROPERTIES_H_INCLUDED
#define PROPERTIES_H_INCLUDED


#define BACKGROUND_TYPE 0
#define WALL_TYPE 1
#define OBJECT_TYPE 2
#define ENEMIES_TYPE 3
#define PLAYER_TYPE 4
#define OBJECT_TYPE_DOOR 5
#define OBJECT_TYPE_KEY 6


typedef struct _Properties Properties;

Properties* Properties_SetInitialPropertiesForType(int type,void * especific);

int Properties_isTransposable(Properties* properties);

void Properties_InteractAction(Properties* targetProperties,Properties* actorProperties );

int Properties_hasAction(Properties* targetProperties);

int Properties_type(Properties* targetProperties);

int Properties_setRemoved(Properties* targetProperties);

int Properties_IsRemoved(Properties* targetProperties);

int Properties_setKey(Properties* playerProperties);

int Properties_getKey(Properties* playerProperties);

void * Properties_getEspecProps(Properties* properties);

#endif // PROPERTIES_H_INCLUDED
