#include "client.h"
#include <commons/log.h>

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_log* configLogger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = log_create("/home/utnso/tp0/client/src/tp0.log","TP0 INFO",true,LOG_LEVEL_INFO);

	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"

	log_info(logger,"Hola, soy un log");
	log_destroy(logger);

	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = config_create("/home/utnso/tp0/client/cliente.config");

	configLogger = log_create("/home/utnso/tp0/client/src/config.log","CONFIG INFO",true,LOG_LEVEL_INFO);

	if (config == NULL)
	{
		log_info(configLogger, "No se pudo crear el config.");
	}else{
		ip = config_get_string_value(config,"IP");
		valor = config_get_string_value(config,"CLAVE");
		puerto = config_get_string_value(config,"PUERTO");
		log_info(configLogger, ip);
		log_info(configLogger, valor);
		log_info(configLogger, puerto);
	}
	

	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	

	// Loggeamos el valor de config


	log_destroy(configLogger);
	/* ---------------- LEER DE CONSOLA ---------------- */

	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él
	
	// iniciar_servidor(); ?????????????????????????

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje
	enviar_mensaje(valor,conexion);
	// Armamos y enviamos el paquete
	paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger;

	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config;

	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido;
	t_log* consoleLogger;

	// La primera te la dejo de yapa
	//leido = readline("> ");

	// El resto, las vamos leyendo y logueando hasta recibir un string vacío
	consoleLogger = log_create("/home/utnso/tp0/client/src/console.log","CONSOLE",true,LOG_LEVEL_INFO);

	while (1)
	{
		leido = readline("> ");
		if (leido)
		{
			add_history(leido);
		}
		if (!strncmp(leido,"",4))
		{
			free(leido);
			break;
		}
		log_info(consoleLogger, leido);
		free(leido);
	}
	
	
	// ¡No te olvides de liberar las lineas antes de regresar!
	
}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete

while (1)
	{
		leido = readline("> ");
		if (leido)
		{
			add_history(leido);
		}
		if (!strncmp(leido,"",4))
		{
			free(leido);
			break;
		}
		agregar_a_paquete(paquete,leido,sizeof(leido));
		free(leido);
	}
	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */
}
