#include "Semaforo.h"

Semaforo :: Semaforo ( const std::string& nombre,const int valorInicial ):valorInicial(valorInicial) {
	key_t clave = ftok ( nombre.c_str(),'a' );
	this->id = semget ( clave,1,0666 | IPC_CREAT );
	if (this->id == -1 ) perror("Error en semget");

	this->inicializar ();
}

Semaforo :: Semaforo ( const std::string& nombre ){
	key_t clave = ftok ( nombre.c_str(),'a' );
	this->id = semget ( clave,1,0666 | IPC_CREAT );
	if (this->id == -1 ) perror("Error en semget");
}

Semaforo::~Semaforo() {
}

int Semaforo :: inicializar () const {

	union semnum {
		int val;
		struct semid_ds* buf;
		ushort* array;
	};

	semnum init;
	init.val = this->valorInicial;
	int resultado = semctl ( this->id,0,SETVAL,init );
	if (resultado == -1 ) perror("Error al inicializar semaforo");
	return resultado;
}

int Semaforo :: p () const {

	struct sembuf operacion;

	operacion.sem_num = 0;	// numero de semaforo
	operacion.sem_op  = -1;	// restar 1 al semaforo
	operacion.sem_flg = SEM_UNDO;

	int resultado = semop ( this->id,&operacion,1 );
	if (resultado == -1 ) perror("Error en p()");
	return resultado;
}

int Semaforo :: pN (int n) const {

	struct sembuf operacion;

	operacion.sem_num = 0;	// numero de semaforo
	operacion.sem_op  = -n;	// restar n al semaforo
	operacion.sem_flg = SEM_UNDO;

	int resultado = semop ( this->id,&operacion,1 );
	if (resultado == -1 ) perror("Error en p()");
	return resultado;
}

int Semaforo :: v () const {

	struct sembuf operacion;

	operacion.sem_num = 0;	// numero de semaforo
	operacion.sem_op  = 1;	// sumar 1 al semaforo
	operacion.sem_flg = SEM_UNDO;

	int resultado = semop ( this->id,&operacion,1 );
	if (resultado == -1 ) perror("Error en v()");
	return resultado;
}

int Semaforo :: vN (const int n) const {

	struct sembuf operacion;

	operacion.sem_num = 0;	// numero de semaforo
	operacion.sem_op  = n;	// sumar 1 al semaforo
	operacion.sem_flg = SEM_UNDO;

	int resultado = semop ( this->id,&operacion,1 );
	if (resultado == -1 ) perror("Error en vN()");
	return resultado;
}


void Semaforo :: eliminar () const {
	int resultado = semctl ( this->id,0,IPC_RMID );
	if (resultado == -1 ) perror("Error al eliminar el semaforo");
}
