#include "../../Shared/include/protocolo.h"

static void* serializar_aprobar_operativos(uint8_t nota1, uint8_t nota2) {
    void *stream = malloc(sizeof(op_code) + sizeof(uint8_t) * 2);
    op_code cop = INICIAR_PROCESO;

    memcpy(stream, &cop, sizeof(op_code));
    memcpy(stream + sizeof(op_code), &nota1, sizeof(uint8_t));
    memcpy(stream + sizeof(op_code) + sizeof(uint8_t), &nota2, sizeof(uint8_t));

    return stream;
}

bool send_aprobar_operativos(int socket_servidor, uint8_t nota1, uint8_t nota2) {
    size_t size = sizeof(op_code) + sizeof(uint8_t) * 2;
    void *stream = serializar_aprobar_operativos(nota1, nota2);

    if (send(socket_servidor, stream, size, 0) != size) {
        free(stream);

        return false;
    }

    free(stream);

    return true;
}


static void deseriaizar_aprobar_operativos(void *stream, uint8_t *nota1, uint8_t *nota2) {
    memcpy(nota1, stream + sizeof(op_code), sizeof(uint8_t));
    memcpy(nota2, stream + sizeof(op_code) + sizeof(uint8_t), sizeof(uint8_t));
}

bool recv_aprobar_operativos(int socket_servidor, uint8_t *nota1, uint8_t *nota2) {
    size_t size = sizeof(op_code) + sizeof(uint8_t) * 2;
    void *stream = malloc(size);

    if (recv(socket_servidor, stream, size, 0) != size) {
        free(stream);

        return false;
    }

    deseriaizar_aprobar_operativos(stream, nota1, nota2);
    free(stream);

    return true;
}

