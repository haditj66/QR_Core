:: generated from colcon_core/shell/template/prefix_chain.bat.em
@echo off

:: This script extends the environment with the environment of other prefix
:: paths which were sourced when this file was generated as well as all
:: packages contained in this prefix path.

:: source chained prefixes
call:_colcon_prefix_chain_bat_call_script "c:\opt\ros\foxy\x64\local_setup.bat"
call:_colcon_prefix_chain_bat_call_script "C:\QR_sync\world\install_win\local_setup.bat"
call:_colcon_prefix_chain_bat_call_script "C:\QR_sync\world\rosqt\install_win\local_setup.bat"
call:_colcon_prefix_chain_bat_call_script "C:\QR_sync\world\rosqt\IF\install_win\local_setup.bat"
call:_colcon_prefix_chain_bat_call_script "C:\QR_sync\gameobjects\rosqt\IF\install_win\local_setup.bat"
call:_colcon_prefix_chain_bat_call_script "C:\QR_sync\gameobjects\install_win\local_setup.bat"
call:_colcon_prefix_chain_bat_call_script "C:\QR_sync\world\rosqt\install_win\\local_setup.bat"
call:_colcon_prefix_chain_bat_call_script "C:\QR_sync\gameobjects\install_win\\local_setup.bat"
call:_colcon_prefix_chain_bat_call_script "c:\opt\ros\foxy\x64\\local_setup.bat"
call:_colcon_prefix_chain_bat_call_script "C:\QR_sync\QR_Core\install_win\\local_setup.bat"
call:_colcon_prefix_chain_bat_call_script "C:\QR_sync\gameobjects\rosqt\IF\install_win\\local_setup.bat"
call:_colcon_prefix_chain_bat_call_script "C:\QR_sync\world\rosqt\IF\install_win\\local_setup.bat"
call:_colcon_prefix_chain_bat_call_script "C:\QR_sync\world\install_win\\local_setup.bat"

:: source this prefix
call:_colcon_prefix_chain_bat_call_script "%%~dp0local_setup.bat"

goto:eof


:: function to source another script with conditional trace output
:: first argument: the path of the script
:_colcon_prefix_chain_bat_call_script
  if exist "%~1" (
    if "%COLCON_TRACE%" NEQ "" echo call "%~1"
    call "%~1%"
  ) else (
    echo not found: "%~1" 1>&2
  )
goto:eof
