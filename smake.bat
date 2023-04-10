rem @echo off
IF "%1"=="main_controller.c" (
	set updated=0
	IF NOT EXIST %1 (
		set updated=1
		echo %1 missing
		goto :eof
	)

	IF  "%~t1" gtr "%~2" (
		echo main_controller.c was updated
		set updated=1
		goto :eof
	)
	goto :eof
)

IF "%1"=="resource.rc" (
	set updated=0
	IF NOT EXIST %1 (
		set updated=1
		echo %1 missing
		goto :eof
	)

	IF  "%~t1" gtr "%~2" (
		echo resource.rc was updated
		set updated=1
		goto :eof
	)
	goto :eof
)

IF "%1"=="main.c" (
	set updated=0
	IF NOT EXIST %1 (
		set updated=1
		echo %1 missing
		goto :eof
	)

	IF  "%~t1" gtr "%~2" (
		echo main.c was updated
		set updated=1
		goto :eof
	)
	goto :eof
)

IF "%1"=="random.c" (
	set updated=0
	IF NOT EXIST %1 (
		set updated=1
		echo %1 missing
		goto :eof
	)

	IF  "%~t1" gtr "%~2" (
		echo random.c was updated
		set updated=1
		goto :eof
	)
	goto :eof
)


IF "%1"=="main_controller.o" (
	echo processing main_controller.o

	IF NOT EXIST %1 (
		echo tcc -o %1       -lcomdlg32  -m32 -b  main_controller.c
		tcc -o %1       -lcomdlg32  -m32 -b  main_controller.c
		set updated=1
		goto :eof 
	)

	call smake main_controller.c "%~t1"
	IF updated==1 (
		echo main_controller.c was updated
		echo tcc -o %1       -lcomdlg32  -m32 -b  main_controller.c
		tcc -o %1       -lcomdlg32  -m32 -b  main_controller.c
		rem updated already = 1 no need to set it again
		goto :eof
	)

	IF "%~2" neq "" (
		set updated=0
		IF  "%~t1" gtr "%~2" (
			set updated=1
			echo main_controller.o was updated %~t1
			goto :eof
		)
		echo main_controller.o is up to date (not recently updated)
		goto :eof
	)

	echo nothing to do for main_controller.o
	goto :eof
)


IF "%1"=="resource.res" (
	echo processing resource.res
	IF NOT EXIST %1 (
		echo GoRc.exe /r /fo   %1  resource.rc
		GoRc.exe /r /fo   %1  resource.rc
		set updated=1
		goto :eof 
	)

	call smake resource.rc "%~t1"
	IF updated==1 (
		echo resource.rc was updated
		echo GoRc.exe /r /fo   %1  resource.rc
		GoRc.exe /r /fo   %1  resource.rc
		rem updated already = 1 no need to set it again
		goto :eof
	)

	IF "%~2" neq "" (
		set updated=0
		IF  "%~t1" gtr "%~2" (
			set updated=1
			echo resource.res was updated %~t1
			goto :eof
		)
			echo resource.res up to date (not recently updated)
			goto :eof
	)

	echo nothing to do for resource.res

	goto :eof
)


IF "%1"=="main.o" (
	echo processing main.o

	IF NOT EXIST %1 (
		echo tcc -o %1       -lcomdlg32  -m32 -b  main.c
		tcc -o %1       -lcomdlg32  -m32 -b  main.c
		set updated=1
		goto :eof 
	)

	call smake main.c "%~t1"
	IF updated==1 (
		echo main.c was updated
		echo tcc -o %1       -lcomdlg32  -m32 -b  main.c
		tcc -o %1       -lcomdlg32  -m32 -b  main.c
		rem updated already = 1 no need to set it again
		goto :eof
	)

	IF "%~2" neq "" (
		set updated=0
		IF  "%~t1" gtr "%~2" (
			set updated=1
			echo main.o was updated %~t1
			goto :eof
		)
		echo main.o is up to date (not recently updated)
		goto :eof
	)

	echo nothing to do for main.o
	goto :eof
)


IF "%1"=="random.o" (
	echo processing random.o

	IF NOT EXIST %1 (
		echo tcc -o %1       -lcomdlg32  -m32 -b  random.c
		tcc -o %1       -lcomdlg32  -m32 -b  random.c
		set updated=1
		goto :eof 
	)

	call smake random.c "%~t1"
	IF updated==1 (
		echo random.c was updated
		echo tcc -o %1       -lcomdlg32  -m32 -b  random.c
		tcc -o %1       -lcomdlg32  -m32 -b  random.c
		rem updated already = 1 no need to set it again
		goto :eof
	)

	IF "%~2" neq "" (
		set updated=0
		IF  "%~t1" gtr "%~2" (
			set updated=1
			echo random.o was updated %~t1
			goto :eof
		)
		echo random.o is up to date (not recently updated)
		goto :eof
	)

	echo nothing to do for random.o
	goto :eof
)


IF "%1"=="physics.exe" goto make_exe
IF "%1"=="all"      goto make_exe
IF "%1"==""         goto make_exe
goto :eof

:make_exe	
set updated2=0

	call smake main_controller.o "%~t1"
	set /a updated2=updated2 + updated

	call smake resource.res "%~t1"
	set /a updated2=updated2 + updated

	call smake main.o "%~t1"
	set /a updated2=updated2 + updated

	call smake random.o "%~t1"
	set /a updated2=updated2 + updated

 
	IF updated2 gtr 0 (
		tcc -o physics.exe       -lcomdlg32  -m32 -b  main_controller.o resource.res main.o random.o
		goto :eof
	)
	echo up to date, nothing to do 
)
