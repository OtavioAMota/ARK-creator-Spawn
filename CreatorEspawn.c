#include <conio.h>
#include <stdio.h>
#include <string.h>

char ID_Dino[200];
char ID_Dino_Sub1[200];
char ID_Dino_Sub2[200];
char ID_Dino_Remo[200];
char Dino_Tag[200];
char Local_Name[200];
char Gerator_ComandSpawn[10000];
char op='0';
float User_Peso_Entrada=0;
float Max_Peso_Entrada=0;
float Min_Peso_Entrada=0;
int NumDinos;
int i=0;
int j=0;
int MaxLevel = 1500;
double Exp_level, formula;
double OverMaxExpPlayer;
double OverMaxExpDino;
FILE *file;

void Ajuda(){
	file = fopen("Help.txt","w");
	fprintf(file,"Ola!\nTopicos:\n*1-Como colocar as linhas de codigo:\nEncontre a pasta: ARK\\ShooterGame\\Saved\\Config\\WindowsNoEditor.\nAbra o Arquivo:Game.ini.\nEm baixo da linha:\"[/Script/ShooterGame.ShooterGameMode]\" coloque o seu codigo.\nAgora é so iniciar o jogo e testar!");
	fclose(file);
	system("start Help.txt");
}

void CriarSpawn(){
	printf("Nome do Local:");
	fgets(Local_Name, 201, stdin);
	Local_Name[strcspn(Local_Name, "\n")] = 0;
	printf("\nQuantos dinos quer adicionar em %s:",Local_Name);
	scanf("%d",&NumDinos);
	fflush(stdin);
	for(j=1;j<=NumDinos;j++){
		fflush(stdin);
		printf("ID do Dino-%d:",j);
		fgets(ID_Dino, 201, stdin);
		ID_Dino[strcspn(ID_Dino, "\n")] = 0;

		printf("Name Tag do Dino-%d:",j);
		fgets(Dino_Tag, 201, stdin);
		Dino_Tag[strcspn(Dino_Tag, "\n")] = 0;
		printf("Quantidade de especies no local %s:",Local_Name);
		scanf("%f",&User_Peso_Entrada);
		Min_Peso_Entrada=((User_Peso_Entrada+1)/100)/2;
		Max_Peso_Entrada=((User_Peso_Entrada+1)/100)/1.8;

		file = fopen("Game.ini","a");
		fprintf(file,"ConfigAddNPCSpawnEntriesContainer=(NPCSpawnEntriesContainerClassString=\"%s_C\",NPCSpawnEntries=((AnEntryName=\"%s\",EntryWeight=%f,NPCsToSpawnStrings=(\"%s\"))),NPCSpawnLimits=((NPCClassString=\"%s\",MaxPercentageOfDesiredNumToAllow=%f))))\n",Local_Name,Dino_Tag,Min_Peso_Entrada,ID_Dino,ID_Dino,Max_Peso_Entrada);
		fclose(file);
		file = fopen("num.ini","a");
		fprintf(file,"%s_C",Local_Name);
		fclose(file);
	}
	for(i=0;i<200;i++){
		Local_Name[i]=0;
		ID_Dino[i]=0;
		Dino_Tag[i]=0;
	}
	printf(" Concluido!");
	_sleep(500);
}
void SubSpawn(){
	printf("\nQuantos dinos quer substituir:");
	scanf("%d",&NumDinos);
	fflush(stdin);
	for(j=1;j<=NumDinos;j++){
		printf("ID do dino que sera substituido:");
		fgets(ID_Dino_Sub1, 201, stdin);
		ID_Dino_Sub1[strcspn(ID_Dino_Sub1, "\n")] = 0;

		printf("ID do dino que ficara no lugar:");
		fgets(ID_Dino_Sub2, 201, stdin);
		ID_Dino_Sub2[strcspn(ID_Dino_Sub2, "\n")] = 0;//Tira a quebra de linha

		file = fopen("Game.ini","a");
		fprintf(file,"NPCReplacements = ( FromClassName = \"%s\", ToClassName = \"%s\")",ID_Dino_Sub1,ID_Dino_Sub2);
		fclose(file);
	}
	printf(" Concluido!");
	_sleep(500);
}

void DeletSpawnDino(){// Deleta o spawn de dino
	printf("Quantos dinos quer deletar:");
	scanf("%d",&NumDinos);
	fflush(stdin);
	for(j=1;j<=NumDinos;j++){
		printf("ID do dino que sera Deletado:");
		fgets(ID_Dino_Remo, 201, stdin);
		ID_Dino_Remo[strcspn(ID_Dino_Remo, "\n")] = 0;
		printf("\nEditando Arquivo.");
		file = fopen("Game.ini","a");
		fprintf(file,"NPCReplacements = (FromClassName = \"%s\")",ID_Dino_Remo);
		fclose(file);
	}
	printf(" Concluido!");
	_sleep(500);
}

void LimparArq(){
	printf("\nLimpando Arquivo.");
	file = fopen("Game.ini","w");
	file = fopen("num.ini","w");
	sleep(1);
	printf(".");
	_sleep(500);
	fprintf(file,"");
	printf(".");
	_sleep(500);
	printf(".");
	fclose(file);
	printf(" Concluido!");
}

void AddLevel(){
	printf("Escolha o level maximo:");
	scanf("%d",&MaxLevel);
	OverMaxExpPlayer = 501000*MaxLevel;
	OverMaxExpDino = 460000*MaxLevel;
	file = fopen("Game.ini","w");
	fprintf(file,"OverrideMaxExperiencePointsPlayer=%.0f\n",OverMaxExpPlayer);
	fprintf(file,"OverrideMaxExperiencePointsDino=%.0f\n",OverMaxExpDino);
	fprintf(file,"LevelExperienceRampOverrides=(");
	for(i=0; i<=MaxLevel;i++){
		formula=500000*i;
		if(i==MaxLevel){
			fprintf(file,"ExperiencePointsForLevel[%d]=%.0f)",i,formula);
		}else{
			fprintf(file,"ExperiencePointsForLevel[%d]=%.0f,\n",i,formula);
		}
	}
	fclose(file);
}

int main(){
	system("color 70&title ArkEditorSpawn V0.07 by: Randow-137");
	while(1==1){
		fflush(stdin);
		op='0';
		system("cls");
		printf("-------MENU-------\n");
		printf("1-Ajuda\n");
		printf("2-Lista de Locais\n");
		printf("3-Lista de Dinos\n");
		printf("4-Criar Spawn\n");
		printf("5-Substituir Spawn de Dino\n");
		printf("6-Deletar Spawn de Dino\n");
		printf("7-Limpar Game.ini\n");
		printf("8-Editar level Maximo(Dino/Jogador)\n");
		printf("------------------\n");
		op = getch();
		switch(op){
			case '1':
				Ajuda();
				break;
			case '2':
				system("start https://ark.gamepedia.com/Spawn_Entries");
				break;
			case '3':
				system("start https://ark.gamepedia.com/Creature_IDs");
				break;
			case '4':
				CriarSpawn();
				break;
			case '5':
				SubSpawn();
				break;
			case '6':
				DeletSpawnDino();
				break;
			case '7':
				LimparArq();
				break;
			case '8':
				AddLevel();
		}
	}
}
