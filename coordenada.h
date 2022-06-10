typedef struct coordernada Coordenada;
typedef struct listaCoordendas ListaCoordenadas;

Coordenada *criarCoordenada(int, int);
void destruirCoordenada(Coordenada *);

ListaCoordenadas *criarListaCoordenadas();
void destruirListaCoordenadas(ListaCoordenadas *);

void inserirCoordenada(ListaCoordenadas *, Coordenada *);

void imprimirListaCoordenadas(ListaCoordenadas *);