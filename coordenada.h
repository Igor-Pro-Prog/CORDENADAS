typedef struct coordernada Coordenada;
typedef struct listaCoordendas ListaCoordenadas;

Coordenada *criarCoordenada(float, float);
void destruirCoordenada(Coordenada *);

ListaCoordenadas *criarListaCoordenadas();
void destruirListaCoordenadas(ListaCoordenadas *);

void inserirCoordenada(ListaCoordenadas *, Coordenada *);

void imprimirListaCoordenadas(ListaCoordenadas *);