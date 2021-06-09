color a
echo off
title ARKSpawn Creature by Randow
cls
:menu
cls
set op=0
echo -------MENU-------
echo %comandARK%.
echo %PesoEntra%
echo %MaxPesoEntra%
echo 1-Criar Spawn(Dino:%IDino%)(Local:%LocalName%)
echo 2-Criar arquivo.txt
echo 3-Lista de dinos
echo 4-Lista de Locais
echo 5-Sair
echo -------    -------
set /p op=Opcao:
if %op% equ 1 (cls&goto CriarSpawn)
if %op% equ 2 goto CriarArquivo
if %op% equ 3 goto ListDino
if %op% equ 4 goto ListEntries
if %op% equ 5 exit
goto menu
:CriarArquivo
echo %comandARK%>>Comand_ARK.txt
echo  ---->>Comand_ARK.txt
goto menu
:CriarSpawn
echo *Dica: cuidado, dinos podem mudar o ecosistema do lugar!
echo *Dica: Consulte as listas de dinos e Locais no menu!
set /p IDino= ID do dino:
set /p DinoTag= Name Tag do dino:
set /p LocalName= Nome do local:
echo Conte quantos dinos ja existem no local escolhido e coloque no peso de entrada.
echo Consulte a Lista de Locais (exemplo: local escolhido:DinoSpawnEntriesBeach Peso de entrada:13).
set /p userPesoEnt= Peso de entrada:
set /a PesoEntra=((%userPesoEnt%+1)/100)/2
set /a MaxPesoEntra=((%userPesoEnt%+1)/100)/1.9
set comandARK=ConfigAddNPCSpawnEntriesContainer=(NPCSpawnEntriesContainerClassString="%LocalName%_C",NPCSpawnEntries=((AnEntryName="%DinoTag%",EntryWeight=%PesoEntra%,NPCsToSpawnStrings=("%IDino%")),NPCSpawnLimits=((NPCClassString="%IDino%",MaxPercentageOfDesiredNumToAllow=%MaxPesoEntra%)))
goto menu
:ListDino
start https://ark.gamepedia.com/Creature_IDs
goto menu
:ListEntries
start https://ark.gamepedia.com/Spawn_Entries
goto menu