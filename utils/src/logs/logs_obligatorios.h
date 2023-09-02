#ifndef LOGS_OBLIGATORIOS_H_
#define LOGS_OBLIGATORIOS_H_
/************************** LOGS OBLIGATORIOS ********************************************/

/****************************** KERNEL ***************************************************/
#define CREACION_DE_PROCESO "Se crea el proceso %d"
#define FIN_DE_PROCESO "Finaliza el proceso <PID> - Motivo: <SUCCESS / INVALID_RESOURCE /INVALID_WRITE>"
#define CAMBIO_DE_ESTADO "PID: <PID> - Estado Anterior: <ESTADO_ANTERIOR> - Estado Actual: <ESTADO_ACTUAL>"
#define MOTIVO_DE_BLOQUEO "PID: <PID> - Bloqueado por: <SLEEP / NOMBRE_RECURSO / NOMBRE_ARCHIVO>"
#define FIN_DE_QUATUM "PID: <PID> - Desalojado por fin de Quantum"
#define INGRESO_A_READY "Cola Ready <ALGORITMO>: [<LISTA DE PIDS>]"
#define WAIT "PID: <PID> - Wait: <NOMBRE RECURSO> - Instancias: <INSTANCIAS RECURSO>"
// Nota: El valor de las instancias es después de ejecutar el Wait
#define SIGNAL "PID: <PID> - Signal: <NOMBRE RECURSO> - Instancias: <INSTANCIAS RECURSO>"
//Nota: El valor de las instancias es después de ejecutar el Signal
#define PAGE_FAULT "Page Fault PID: <PID> - Pagina: <Página>"
#define ABRIR_ARCHIVO "PID: <PID> - Abrir Archivo: <NOMBRE ARCHIVO>"
#define CERRAR_ARCHIVO "PID: <PID> - Cerrar Archivo: <NOMBRE ARCHIVO>"
#define ACTUALIZAR_PUNTERO_ARCHIVO "PID: <PID> - Actualizar puntero Archivo: <NOMBRE ARCHIVO> - Puntero <PUNTERO>" Nota: El valor del puntero debe ser luego de ejecutar F_SEEK.
#define TRUNCAR_ARCHIVO "PID: <PID> - Archivo: <NOMBRE ARCHIVO> - Tamaño: <TAMAÑO>"
#define LEER_ARCHIVO "PID: <PID> - Leer Archivo: <NOMBRE ARCHIVO> - Puntero <PUNTERO> - Dirección Memoria <DIRECCIÓN MEMORIA> - Tamaño <TAMAÑO>"
#define ESCRIBIR_ARCHIVO "PID: <PID> - Escribir Archivo: <NOMBRE ARCHIVO> - Puntero <PUNTERO> - Dirección Memoria <DIRECCIÓN MEMORIA> - Tamaño <TAMAÑO>"
#define PROCESO_DE_DETECCION_DEADLOCK "ANÁLISIS DE DETECCIÓN DE DEADLOCK"
#define DETECCION_DE_DEADLOCK "Deadlock detectado: <PID> - Recursos en posesión <RECURSO_1>, <RECURSO_2>, <RECURSO_N> - Recurso requerido: <RECURSO_REQUERIDO>" // (por cada proceso dentro del deadlock)
#define PAUSA_PLANIFICACION "PAUSA DE PLANIFICACIÓN"
#define INICIO_PLANIFICACION "INICIO DE PLANIFICACIÓN"

/****************************** CPU ***************************************************/
#define FETCH_INSTRUCCION "PID: <PID> - FETCH - Program Counter: <PROGRAM_COUNTER>"
#define INSTRUCCION_EJECUTADA "PID: <PID> - Ejecutando: <INSTRUCCION> - <PARAMETROS>"
#define OBTENER_MARCO "PID: <PID> - OBTENER MARCO - Página: <NUMERO_PAGINA> - Marco: <NUMERO_MARCO>"
#define LECTURA_ESCRITURA_MEMORIA "PID: <PID> - Acción: <LEER / ESCRIBIR> - Dirección Física: <DIRECCION_FISICA> - Valor: <VALOR LEIDO / ESCRITO>"

/****************************** MEMORIA ***************************************************/
#define CREACION_DESTRUCCION_TABLA_DE_PAGINAS "PID: <PID> - Tamaño: <CANTIDAD_PAGINAS>"
#define ACCESO_TABLA_DE_PAGINAS "PID: <PID> - Pagina: <PAGINA> - Marco: <MARCO>"
#define ACCESO_ESPACIO_DE_USUARIO "PID: <PID> - Accion: <LEER / ESCRIBIR> - Direccion fisica: <DIRECCION_FISICA>"
#define REEMPLAZO_PAGINA "REEMPLAZO - PID: <PID> - Page Out: <PID>-<NRO_PAGINA> - Page In: <PID>-<NRO_PAGINA>"
#define LECTURA_DE_PAGINA_DE_SWAP "SWAP IN - PID: <PID> - Marco: <MARCO> - Page In: <PID>-<NRO_PAGINA>"
#define ESCRITURA_DE_PAGINA_EN_SWAP "SWAP OUT - PID: <PID> - Marco: <MARCO> - Page Out: <PID>-<NRO_PAGINA>"

/****************************** FILE-SYSTEM ***************************************************/
#define CREAR_ARCHIVO "Crear Archivo: <NOMBRE_ARCHIVO>"
#define APERTURA_DE_ARCHIVO "Abrir Archivo: <NOMBRE_ARCHIVO>"
#define TRUNCATE_DE_ARCHIVO "Truncar Archivo: <NOMBRE_ARCHIVO> - Tamaño: <TAMAÑO>"
#define LECTURA_DE_ARCHIVO "Leer Archivo: <NOMBRE_ARCHIVO> - Puntero: <PUNTERO ARCHIVO> - Memoria: <DIRECCION MEMORIA>"
#define ESCRITURA_DE_ARCHIVO "Escribir Archivo: <NOMBRE_ARCHIVO> - Puntero: <PUNTERO ARCHIVO> - Memoria: <DIRECCION MEMORIA>"
#define ACCESO_A_FAT "Acceso FAT - Entrada: <NRO_ENTRADA_FAT> - Valor: <VALOR_ENTRADA_FAT>"
#define ACCESO_A_BLOQUE_ARCHIVO "Acceso Bloque - Archivo: <NOMBRE_ARCHIVO> - Bloque Archivo: <NUMERO_BLOQUE_ARCHIVO> - Bloque FS: <NUMERO_BLOQUE_FS>"
#define ACCESO_A_BLOQUE_SWAP "Acceso SWAP: <NRO_BLOQUE>"

#endif