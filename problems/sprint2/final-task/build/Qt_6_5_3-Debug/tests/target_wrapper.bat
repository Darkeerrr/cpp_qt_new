@echo off
SetLocal EnableDelayedExpansion
(set PATH=D:\programs\Qt\6.5.3\msvc2019_64\bin;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=D:\programs\Qt\6.5.3\msvc2019_64\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=D:\programs\Qt\6.5.3\msvc2019_64\plugins
)
%*
EndLocal
