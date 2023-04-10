@echo off

if 0%1%==01 goto perfom_task1
if 0%1%==02 goto perfom_task2
if 0%1%==03 goto perfom_task3
if 0%1%==04 goto perfom_task4

echo Usage:  MakeTarget index 
echo where index = 1 - 4

echo 1. make main_controller.o 
echo 2. make resource.o 
echo 3. make main.o 
echo 4. make random.o 

goto done_all

:perfom_task1
cls
make main_controller.o
goto done_all

:perfom_task2
cls
make resource.o
goto done_all

:perfom_task3
cls
make main.o
goto done_all

:perfom_task4
cls
make random.o
goto done_all


:done_all
echo done
