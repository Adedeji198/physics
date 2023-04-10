physics_exe_C_SRC   =  main_controller.c main.c random.c 
physics_exe_CPP_SRC =  
physics_exe_RC_SRC  =  resource.rc 
physics_exe_LIB_SRC =  
physics_exe_O_SRC   =  $(patsubst %.c,%.o, $(physics_exe_C_SRC)) $(patsubst %.cpp,%.o,$(physics_exe_CPP_SRC)) $(patsubst %.rc,%.obj, $(physics_exe_RC_SRC)) 




#Tools
RM       = rm.exe -f
CC       = tcc -D__DEBUG__
WINDRES  = GoRc.exe  
ARCHIVE  = tcc -ar rcsv


#Compiler Environment
LIBS     =       -lcomdlg32  -m32 -b
INC      =  


physics_exe = physics.exe

all:  $(physics_exe) 

touch: 
	touch  $(physics_exe_C_SRC) $(physics_exe_CPP_SRC) $(physics_exe_RC_SRC)

clean: 
	$(RM)  $(physics_exe_O_SRC) $(physics_exe)


$(physics_exe): $(physics_exe_O_SRC)
	$(CC) $(physics_exe_O_SRC)  -o $(physics_exe) $(physics_exe_LIB_SRC) $(LIBS) 

%.o: %.c
	$(CC) -c $(INC) -o $@ $^ $(warning creating c object $@)

%.o: %.cpp
	$(CC) -c $(INC) -o $@ $^ $(warning creating cpp object $@)


%.obj: %.rc
	$(WINDRES)  /of $@   $^ $(warning creating rc object $@)


