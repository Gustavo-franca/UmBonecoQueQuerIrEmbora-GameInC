
WORKDIR = %cd%

CC = gcc.exe
CXX = g++.exe
AR = ar.exe
LD = g++.exe
WINDRES = windres.exe

INC = 
CFLAGS = -Wall
RESINC = 
LIBDIR = 
LIB = 
LDFLAGS = 

INC_DEBUG = $(INC)
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj\\Debug
DEP_DEBUG = 
OUT_DEBUG = bin\\Debug\\RPG-UmBonecoQueQuerIrEmbora.exe

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -O2
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS) -s
OBJDIR_RELEASE = obj\\Release
DEP_RELEASE = 
OUT_RELEASE = bin\\Release\\RPG-UmBonecoQueQuerIrEmbora.exe

OBJ_DEBUG = $(OBJDIR_DEBUG)\\src\\Uteis\\console\\console.o $(OBJDIR_DEBUG)\\src\\Modules\\Map\\map.o $(OBJDIR_DEBUG)\\src\\Modules\\MenuOptions\\MenuOptions.o $(OBJDIR_DEBUG)\\src\\Modules\\Player\\player.o $(OBJDIR_DEBUG)\\src\\Modules\\Properties\\properties.o $(OBJDIR_DEBUG)\\src\\Modules\\Element\\element.o $(OBJDIR_DEBUG)\\src\\Uteis\\pickUpKey\\pickUpKey.o $(OBJDIR_DEBUG)\\src\\View\\Arena\\ArenaView.o $(OBJDIR_DEBUG)\\src\\View\\Menu\\MenuView.o $(OBJDIR_DEBUG)\\src\\main.o $(OBJDIR_DEBUG)\\src\\GameMaps\\GameMap.o $(OBJDIR_DEBUG)\\src\\Controllers\\ElementController\\ElementController.o $(OBJDIR_DEBUG)\\src\\Controllers\\GameController\\GameController.o $(OBJDIR_DEBUG)\\src\\Controllers\\MenuController\\MenuController.o $(OBJDIR_DEBUG)\\src\\Controllers\\PlayerController\\PlayerController.o $(OBJDIR_DEBUG)\\src\\Controllers\\Arena\\ArenaController.o $(OBJDIR_DEBUG)\\src\\GameMaps\\level1\\level1.o $(OBJDIR_DEBUG)\\src\\Modules\\Arena\\Arena.o $(OBJDIR_DEBUG)\\src\\Modules\\Door\\door.o $(OBJDIR_DEBUG)\\src\\Modules\\Element\\ElementList\\ElementList.o

OBJ_RELEASE = $(OBJDIR_RELEASE)\\src\\Uteis\\console\\console.o $(OBJDIR_RELEASE)\\src\\Modules\\Map\\map.o $(OBJDIR_RELEASE)\\src\\Modules\\MenuOptions\\MenuOptions.o $(OBJDIR_RELEASE)\\src\\Modules\\Player\\player.o $(OBJDIR_RELEASE)\\src\\Modules\\Properties\\properties.o $(OBJDIR_RELEASE)\\src\\Modules\\Element\\element.o $(OBJDIR_RELEASE)\\src\\Uteis\\pickUpKey\\pickUpKey.o $(OBJDIR_RELEASE)\\src\\View\\Arena\\ArenaView.o $(OBJDIR_RELEASE)\\src\\View\\Menu\\MenuView.o $(OBJDIR_RELEASE)\\src\\main.o $(OBJDIR_RELEASE)\\src\\GameMaps\\GameMap.o $(OBJDIR_RELEASE)\\src\\Controllers\\ElementController\\ElementController.o $(OBJDIR_RELEASE)\\src\\Controllers\\GameController\\GameController.o $(OBJDIR_RELEASE)\\src\\Controllers\\MenuController\\MenuController.o $(OBJDIR_RELEASE)\\src\\Controllers\\PlayerController\\PlayerController.o $(OBJDIR_RELEASE)\\src\\Controllers\\Arena\\ArenaController.o $(OBJDIR_RELEASE)\\src\\GameMaps\\level1\\level1.o $(OBJDIR_RELEASE)\\src\\Modules\\Arena\\Arena.o $(OBJDIR_RELEASE)\\src\\Modules\\Door\\door.o $(OBJDIR_RELEASE)\\src\\Modules\\Element\\ElementList\\ElementList.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	cmd /c if not exist bin\\Debug md bin\\Debug
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\Uteis\\console md $(OBJDIR_DEBUG)\\src\\Uteis\\console
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\Modules\\Map md $(OBJDIR_DEBUG)\\src\\Modules\\Map
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\Modules\\MenuOptions md $(OBJDIR_DEBUG)\\src\\Modules\\MenuOptions
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\Modules\\Player md $(OBJDIR_DEBUG)\\src\\Modules\\Player
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\Modules\\Properties md $(OBJDIR_DEBUG)\\src\\Modules\\Properties
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\Modules\\Element md $(OBJDIR_DEBUG)\\src\\Modules\\Element
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\Uteis\\pickUpKey md $(OBJDIR_DEBUG)\\src\\Uteis\\pickUpKey
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\View\\Arena md $(OBJDIR_DEBUG)\\src\\View\\Arena
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\View\\Menu md $(OBJDIR_DEBUG)\\src\\View\\Menu
	cmd /c if not exist $(OBJDIR_DEBUG)\\src md $(OBJDIR_DEBUG)\\src
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\GameMaps md $(OBJDIR_DEBUG)\\src\\GameMaps
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\Controllers\\ElementController md $(OBJDIR_DEBUG)\\src\\Controllers\\ElementController
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\Controllers\\GameController md $(OBJDIR_DEBUG)\\src\\Controllers\\GameController
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\Controllers\\MenuController md $(OBJDIR_DEBUG)\\src\\Controllers\\MenuController
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\Controllers\\PlayerController md $(OBJDIR_DEBUG)\\src\\Controllers\\PlayerController
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\Controllers\\Arena md $(OBJDIR_DEBUG)\\src\\Controllers\\Arena
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\GameMaps\\level1 md $(OBJDIR_DEBUG)\\src\\GameMaps\\level1
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\Modules\\Arena md $(OBJDIR_DEBUG)\\src\\Modules\\Arena
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\Modules\\Door md $(OBJDIR_DEBUG)\\src\\Modules\\Door
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\Modules\\Element\\ElementList md $(OBJDIR_DEBUG)\\src\\Modules\\Element\\ElementList

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)\\src\\Uteis\\console\\console.o: src\\Uteis\\console\\console.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\Uteis\\console\\console.c -o $(OBJDIR_DEBUG)\\src\\Uteis\\console\\console.o

$(OBJDIR_DEBUG)\\src\\Modules\\Map\\map.o: src\\Modules\\Map\\map.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\Modules\\Map\\map.c -o $(OBJDIR_DEBUG)\\src\\Modules\\Map\\map.o

$(OBJDIR_DEBUG)\\src\\Modules\\MenuOptions\\MenuOptions.o: src\\Modules\\MenuOptions\\MenuOptions.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\Modules\\MenuOptions\\MenuOptions.c -o $(OBJDIR_DEBUG)\\src\\Modules\\MenuOptions\\MenuOptions.o

$(OBJDIR_DEBUG)\\src\\Modules\\Player\\player.o: src\\Modules\\Player\\player.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\Modules\\Player\\player.c -o $(OBJDIR_DEBUG)\\src\\Modules\\Player\\player.o

$(OBJDIR_DEBUG)\\src\\Modules\\Properties\\properties.o: src\\Modules\\Properties\\properties.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\Modules\\Properties\\properties.c -o $(OBJDIR_DEBUG)\\src\\Modules\\Properties\\properties.o

$(OBJDIR_DEBUG)\\src\\Modules\\Element\\element.o: src\\Modules\\Element\\element.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\Modules\\Element\\element.c -o $(OBJDIR_DEBUG)\\src\\Modules\\Element\\element.o

$(OBJDIR_DEBUG)\\src\\Uteis\\pickUpKey\\pickUpKey.o: src\\Uteis\\pickUpKey\\pickUpKey.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\Uteis\\pickUpKey\\pickUpKey.c -o $(OBJDIR_DEBUG)\\src\\Uteis\\pickUpKey\\pickUpKey.o

$(OBJDIR_DEBUG)\\src\\View\\Arena\\ArenaView.o: src\\View\\Arena\\ArenaView.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\View\\Arena\\ArenaView.c -o $(OBJDIR_DEBUG)\\src\\View\\Arena\\ArenaView.o

$(OBJDIR_DEBUG)\\src\\View\\Menu\\MenuView.o: src\\View\\Menu\\MenuView.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\View\\Menu\\MenuView.c -o $(OBJDIR_DEBUG)\\src\\View\\Menu\\MenuView.o

$(OBJDIR_DEBUG)\\src\\main.o: src\\main.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\main.c -o $(OBJDIR_DEBUG)\\src\\main.o

$(OBJDIR_DEBUG)\\src\\GameMaps\\GameMap.o: src\\GameMaps\\GameMap.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\GameMaps\\GameMap.c -o $(OBJDIR_DEBUG)\\src\\GameMaps\\GameMap.o

$(OBJDIR_DEBUG)\\src\\Controllers\\ElementController\\ElementController.o: src\\Controllers\\ElementController\\ElementController.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\Controllers\\ElementController\\ElementController.c -o $(OBJDIR_DEBUG)\\src\\Controllers\\ElementController\\ElementController.o

$(OBJDIR_DEBUG)\\src\\Controllers\\GameController\\GameController.o: src\\Controllers\\GameController\\GameController.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\Controllers\\GameController\\GameController.c -o $(OBJDIR_DEBUG)\\src\\Controllers\\GameController\\GameController.o

$(OBJDIR_DEBUG)\\src\\Controllers\\MenuController\\MenuController.o: src\\Controllers\\MenuController\\MenuController.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\Controllers\\MenuController\\MenuController.c -o $(OBJDIR_DEBUG)\\src\\Controllers\\MenuController\\MenuController.o

$(OBJDIR_DEBUG)\\src\\Controllers\\PlayerController\\PlayerController.o: src\\Controllers\\PlayerController\\PlayerController.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\Controllers\\PlayerController\\PlayerController.c -o $(OBJDIR_DEBUG)\\src\\Controllers\\PlayerController\\PlayerController.o

$(OBJDIR_DEBUG)\\src\\Controllers\\Arena\\ArenaController.o: src\\Controllers\\Arena\\ArenaController.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\Controllers\\Arena\\ArenaController.c -o $(OBJDIR_DEBUG)\\src\\Controllers\\Arena\\ArenaController.o

$(OBJDIR_DEBUG)\\src\\GameMaps\\level1\\level1.o: src\\GameMaps\\level1\\level1.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\GameMaps\\level1\\level1.c -o $(OBJDIR_DEBUG)\\src\\GameMaps\\level1\\level1.o

$(OBJDIR_DEBUG)\\src\\Modules\\Arena\\Arena.o: src\\Modules\\Arena\\Arena.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\Modules\\Arena\\Arena.c -o $(OBJDIR_DEBUG)\\src\\Modules\\Arena\\Arena.o

$(OBJDIR_DEBUG)\\src\\Modules\\Door\\door.o: src\\Modules\\Door\\door.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\Modules\\Door\\door.c -o $(OBJDIR_DEBUG)\\src\\Modules\\Door\\door.o

$(OBJDIR_DEBUG)\\src\\Modules\\Element\\ElementList\\ElementList.o: src\\Modules\\Element\\ElementList\\ElementList.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\Modules\\Element\\ElementList\\ElementList.c -o $(OBJDIR_DEBUG)\\src\\Modules\\Element\\ElementList\\ElementList.o

clean_debug: 
	cmd /c del /f $(OBJ_DEBUG) $(OUT_DEBUG)
	cmd /c rd bin\\Debug
	cmd /c rd $(OBJDIR_DEBUG)\\src\\Uteis\\console
	cmd /c rd $(OBJDIR_DEBUG)\\src\\Modules\\Map
	cmd /c rd $(OBJDIR_DEBUG)\\src\\Modules\\MenuOptions
	cmd /c rd $(OBJDIR_DEBUG)\\src\\Modules\\Player
	cmd /c rd $(OBJDIR_DEBUG)\\src\\Modules\\Properties
	cmd /c rd $(OBJDIR_DEBUG)\\src\\Modules\\Element
	cmd /c rd $(OBJDIR_DEBUG)\\src\\Uteis\\pickUpKey
	cmd /c rd $(OBJDIR_DEBUG)\\src\\View\\Arena
	cmd /c rd $(OBJDIR_DEBUG)\\src\\View\\Menu
	cmd /c rd $(OBJDIR_DEBUG)\\src
	cmd /c rd $(OBJDIR_DEBUG)\\src\\GameMaps
	cmd /c rd $(OBJDIR_DEBUG)\\src\\Controllers\\ElementController
	cmd /c rd $(OBJDIR_DEBUG)\\src\\Controllers\\GameController
	cmd /c rd $(OBJDIR_DEBUG)\\src\\Controllers\\MenuController
	cmd /c rd $(OBJDIR_DEBUG)\\src\\Controllers\\PlayerController
	cmd /c rd $(OBJDIR_DEBUG)\\src\\Controllers\\Arena
	cmd /c rd $(OBJDIR_DEBUG)\\src\\GameMaps\\level1
	cmd /c rd $(OBJDIR_DEBUG)\\src\\Modules\\Arena
	cmd /c rd $(OBJDIR_DEBUG)\\src\\Modules\\Door
	cmd /c rd $(OBJDIR_DEBUG)\\src\\Modules\\Element\\ElementList

before_release: 
	cmd /c if not exist bin\\Release md bin\\Release
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\Uteis\\console md $(OBJDIR_RELEASE)\\src\\Uteis\\console
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\Modules\\Map md $(OBJDIR_RELEASE)\\src\\Modules\\Map
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\Modules\\MenuOptions md $(OBJDIR_RELEASE)\\src\\Modules\\MenuOptions
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\Modules\\Player md $(OBJDIR_RELEASE)\\src\\Modules\\Player
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\Modules\\Properties md $(OBJDIR_RELEASE)\\src\\Modules\\Properties
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\Modules\\Element md $(OBJDIR_RELEASE)\\src\\Modules\\Element
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\Uteis\\pickUpKey md $(OBJDIR_RELEASE)\\src\\Uteis\\pickUpKey
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\View\\Arena md $(OBJDIR_RELEASE)\\src\\View\\Arena
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\View\\Menu md $(OBJDIR_RELEASE)\\src\\View\\Menu
	cmd /c if not exist $(OBJDIR_RELEASE)\\src md $(OBJDIR_RELEASE)\\src
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\GameMaps md $(OBJDIR_RELEASE)\\src\\GameMaps
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\Controllers\\ElementController md $(OBJDIR_RELEASE)\\src\\Controllers\\ElementController
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\Controllers\\GameController md $(OBJDIR_RELEASE)\\src\\Controllers\\GameController
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\Controllers\\MenuController md $(OBJDIR_RELEASE)\\src\\Controllers\\MenuController
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\Controllers\\PlayerController md $(OBJDIR_RELEASE)\\src\\Controllers\\PlayerController
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\Controllers\\Arena md $(OBJDIR_RELEASE)\\src\\Controllers\\Arena
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\GameMaps\\level1 md $(OBJDIR_RELEASE)\\src\\GameMaps\\level1
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\Modules\\Arena md $(OBJDIR_RELEASE)\\src\\Modules\\Arena
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\Modules\\Door md $(OBJDIR_RELEASE)\\src\\Modules\\Door
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\Modules\\Element\\ElementList md $(OBJDIR_RELEASE)\\src\\Modules\\Element\\ElementList

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)\\src\\Uteis\\console\\console.o: src\\Uteis\\console\\console.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\Uteis\\console\\console.c -o $(OBJDIR_RELEASE)\\src\\Uteis\\console\\console.o

$(OBJDIR_RELEASE)\\src\\Modules\\Map\\map.o: src\\Modules\\Map\\map.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\Modules\\Map\\map.c -o $(OBJDIR_RELEASE)\\src\\Modules\\Map\\map.o

$(OBJDIR_RELEASE)\\src\\Modules\\MenuOptions\\MenuOptions.o: src\\Modules\\MenuOptions\\MenuOptions.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\Modules\\MenuOptions\\MenuOptions.c -o $(OBJDIR_RELEASE)\\src\\Modules\\MenuOptions\\MenuOptions.o

$(OBJDIR_RELEASE)\\src\\Modules\\Player\\player.o: src\\Modules\\Player\\player.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\Modules\\Player\\player.c -o $(OBJDIR_RELEASE)\\src\\Modules\\Player\\player.o

$(OBJDIR_RELEASE)\\src\\Modules\\Properties\\properties.o: src\\Modules\\Properties\\properties.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\Modules\\Properties\\properties.c -o $(OBJDIR_RELEASE)\\src\\Modules\\Properties\\properties.o

$(OBJDIR_RELEASE)\\src\\Modules\\Element\\element.o: src\\Modules\\Element\\element.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\Modules\\Element\\element.c -o $(OBJDIR_RELEASE)\\src\\Modules\\Element\\element.o

$(OBJDIR_RELEASE)\\src\\Uteis\\pickUpKey\\pickUpKey.o: src\\Uteis\\pickUpKey\\pickUpKey.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\Uteis\\pickUpKey\\pickUpKey.c -o $(OBJDIR_RELEASE)\\src\\Uteis\\pickUpKey\\pickUpKey.o

$(OBJDIR_RELEASE)\\src\\View\\Arena\\ArenaView.o: src\\View\\Arena\\ArenaView.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\View\\Arena\\ArenaView.c -o $(OBJDIR_RELEASE)\\src\\View\\Arena\\ArenaView.o

$(OBJDIR_RELEASE)\\src\\View\\Menu\\MenuView.o: src\\View\\Menu\\MenuView.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\View\\Menu\\MenuView.c -o $(OBJDIR_RELEASE)\\src\\View\\Menu\\MenuView.o

$(OBJDIR_RELEASE)\\src\\main.o: src\\main.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\main.c -o $(OBJDIR_RELEASE)\\src\\main.o

$(OBJDIR_RELEASE)\\src\\GameMaps\\GameMap.o: src\\GameMaps\\GameMap.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\GameMaps\\GameMap.c -o $(OBJDIR_RELEASE)\\src\\GameMaps\\GameMap.o

$(OBJDIR_RELEASE)\\src\\Controllers\\ElementController\\ElementController.o: src\\Controllers\\ElementController\\ElementController.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\Controllers\\ElementController\\ElementController.c -o $(OBJDIR_RELEASE)\\src\\Controllers\\ElementController\\ElementController.o

$(OBJDIR_RELEASE)\\src\\Controllers\\GameController\\GameController.o: src\\Controllers\\GameController\\GameController.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\Controllers\\GameController\\GameController.c -o $(OBJDIR_RELEASE)\\src\\Controllers\\GameController\\GameController.o

$(OBJDIR_RELEASE)\\src\\Controllers\\MenuController\\MenuController.o: src\\Controllers\\MenuController\\MenuController.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\Controllers\\MenuController\\MenuController.c -o $(OBJDIR_RELEASE)\\src\\Controllers\\MenuController\\MenuController.o

$(OBJDIR_RELEASE)\\src\\Controllers\\PlayerController\\PlayerController.o: src\\Controllers\\PlayerController\\PlayerController.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\Controllers\\PlayerController\\PlayerController.c -o $(OBJDIR_RELEASE)\\src\\Controllers\\PlayerController\\PlayerController.o

$(OBJDIR_RELEASE)\\src\\Controllers\\Arena\\ArenaController.o: src\\Controllers\\Arena\\ArenaController.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\Controllers\\Arena\\ArenaController.c -o $(OBJDIR_RELEASE)\\src\\Controllers\\Arena\\ArenaController.o

$(OBJDIR_RELEASE)\\src\\GameMaps\\level1\\level1.o: src\\GameMaps\\level1\\level1.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\GameMaps\\level1\\level1.c -o $(OBJDIR_RELEASE)\\src\\GameMaps\\level1\\level1.o

$(OBJDIR_RELEASE)\\src\\Modules\\Arena\\Arena.o: src\\Modules\\Arena\\Arena.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\Modules\\Arena\\Arena.c -o $(OBJDIR_RELEASE)\\src\\Modules\\Arena\\Arena.o

$(OBJDIR_RELEASE)\\src\\Modules\\Door\\door.o: src\\Modules\\Door\\door.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\Modules\\Door\\door.c -o $(OBJDIR_RELEASE)\\src\\Modules\\Door\\door.o

$(OBJDIR_RELEASE)\\src\\Modules\\Element\\ElementList\\ElementList.o: src\\Modules\\Element\\ElementList\\ElementList.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\Modules\\Element\\ElementList\\ElementList.c -o $(OBJDIR_RELEASE)\\src\\Modules\\Element\\ElementList\\ElementList.o

clean_release: 
	cmd /c del /f $(OBJ_RELEASE) $(OUT_RELEASE)
	cmd /c rd bin\\Release
	cmd /c rd $(OBJDIR_RELEASE)\\src\\Uteis\\console
	cmd /c rd $(OBJDIR_RELEASE)\\src\\Modules\\Map
	cmd /c rd $(OBJDIR_RELEASE)\\src\\Modules\\MenuOptions
	cmd /c rd $(OBJDIR_RELEASE)\\src\\Modules\\Player
	cmd /c rd $(OBJDIR_RELEASE)\\src\\Modules\\Properties
	cmd /c rd $(OBJDIR_RELEASE)\\src\\Modules\\Element
	cmd /c rd $(OBJDIR_RELEASE)\\src\\Uteis\\pickUpKey
	cmd /c rd $(OBJDIR_RELEASE)\\src\\View\\Arena
	cmd /c rd $(OBJDIR_RELEASE)\\src\\View\\Menu
	cmd /c rd $(OBJDIR_RELEASE)\\src
	cmd /c rd $(OBJDIR_RELEASE)\\src\\GameMaps
	cmd /c rd $(OBJDIR_RELEASE)\\src\\Controllers\\ElementController
	cmd /c rd $(OBJDIR_RELEASE)\\src\\Controllers\\GameController
	cmd /c rd $(OBJDIR_RELEASE)\\src\\Controllers\\MenuController
	cmd /c rd $(OBJDIR_RELEASE)\\src\\Controllers\\PlayerController
	cmd /c rd $(OBJDIR_RELEASE)\\src\\Controllers\\Arena
	cmd /c rd $(OBJDIR_RELEASE)\\src\\GameMaps\\level1
	cmd /c rd $(OBJDIR_RELEASE)\\src\\Modules\\Arena
	cmd /c rd $(OBJDIR_RELEASE)\\src\\Modules\\Door
	cmd /c rd $(OBJDIR_RELEASE)\\src\\Modules\\Element\\ElementList

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

