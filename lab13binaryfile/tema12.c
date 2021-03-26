/*#include<stdio.h>
#include<string.h>
#include<time.h>


struct tar_header
{
    char name[100];
    char mode[8];
    char owner[8];
    char group[8];
    char size[12];
    char modified[12];
    char checksum[8];
    char type[1];
    char link[100];
    char padding[255];
};

void fexpand(FILE* f, size_t amount, int value)
{
    while( amount-- )
    {
        fputc( value, f );
    }
}

void tar_add(FILE* tar_file, const char* file, const char* internal_name)
{

    size_t index = ftell( tar_file );
    size_t offset = index % 512;

    if( offset != 0 )
    {
        fexpand( tar_file, 512 - offset, 0);
    }

    index = ftell( tar_file );


    fexpand( tar_file, sizeof(struct tar_header), 0 );


    FILE* input = fopen( file, "rb" );
    if( input == NULL )
    {
        fprintf( stderr, "Failed to open %s for reading\n", file);
        return;
    }

    while( !feof(input) )
    {
        char buffer[2000];
        size_t read = fread( buffer, 1, 2000, input );
        fwrite( buffer, 1, read, tar_file);
    }


    offset = end % 512;
    if( end != 0 )
    {
        fexpand( tar_file, 512 - offset, 0);
    }

    struct tar_header header;
    memset( &header, 0, sizeof( struct tar_header ) );
    snprintf( header.name, 100, "%s", internal_name  );
    snprintf( header.mode, 8, "%06o ", 0777 ); 
    snprintf( header.owner, 8, "%06o ", 0 ); 
    snprintf( header.group, 8, "%06o ", 0 ); 
    snprintf( header.size, 12, "%011o", end - 512 - index );
    snprintf( header.modified, 12, "%011o ", time(0) );
    memset( header.checksum, ' ', 8);
    header.type[0] = '0';


    size_t checksum = 0;
    int i;
    const unsigned char* bytes = &header;
    for( i = 0; i < sizeof( struct tar_header ); ++i ){
        checksum += bytes[i];
    }

    snprintf( header.checksum, 8, "%06o ", checksum );

    end = ftell(tar_file);

    fseek( tar_file, index, SEEK_SET );
    fwrite( bytes, 1, sizeof( struct tar_header ), tar_file );

    fseek( tar_file, end, SEEK_SET );
    fclose( input );
}

int main( int argc, char* argv[] )
{
    if( argc > 1 )
    {
        FILE* tar = fopen( argv[1], "wb" );

        if( !tar )
        {
            fprintf( stderr, "Failed to open %s for writing\n", argv[1] );
            return 1;
        }

        int i;
        for( i = 2; i < argc; ++i )
        {
            tar_add( tar, argv[i], argv[i] );
        }

        fexpand( tar, 1024, 0);
        fclose( tar );
        return 0;
    }

    fprintf( stderr, "Please specify some file names!\n" );

    return 0;
}*/

#include <stdio.h>

typedef struct _table
{
    unsigned int id, marked;
    char repair_type[256];
    unsigned long long IMEI;
    float price, investment, profit, total_profit, total_influx;

} Repairshop;

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1], "rab");

    if (!file)
    {
        perror("Be carefull at the input, the dark side might be forcing you to miss");
        return 0;
    }

    int operation;
    printf("Enter option: 0 - Add an entity, 1 - Delete an entity, 2 - Display by IMEI the entities , 3 - Mark or Unmark an entity \n");
    scanf(" %d", &operation);

    int counter = 0;
    float profit = 0, influx = 0;


    switch (operation)
    {
    case 0:
    {
        Repairshop phoneobject;
        printf("What happened to your phone? - Enter the problem of it: ");
        scanf("%s", phoneobject.repair_type);

        printf("Enter the IMEI of the phone: ");
        scanf(" %llu", &phoneobject.IMEI);

        printf("Enter price of the repair type of the phone: ");
        scanf(" %f", &phoneobject.price);

        printf("Enter the investment after we did business: ");
        scanf(" %f", &phoneobject.investment);

        phoneobject.profit = phoneobject.price - phoneobject.investment;
        phoneobject.marked = 0;
        phoneobject.total_influx = 0;
        phoneobject.total_profit = 0;
        profit =profit + phoneobject.profit;
        influx =influx + phoneobject.price;

        FILE *output = fopen("tema.bdb", "wb");
        Repairshop aux;
        
        if (fread(&aux, sizeof(Repairshop), 1, file))
        {
            aux.total_profit = profit;
            aux.total_influx = influx;
            counter++;
            fwrite(&aux, sizeof(Repairshop), 1, output);
            while (fread(&aux, sizeof(Repairshop), 1, file))
            {
                fwrite(&aux, sizeof(Repairshop), 1, output);
                counter++;
            }
        }
        else
        {
            phoneobject.total_profit = profit;
            phoneobject.total_influx = influx;
        }
        phoneobject.id = counter++;
        fwrite(&phoneobject, sizeof(Repairshop), 1, output);
        remove(argv[1]);
        rename("tema.bdb", argv[1]);
        break;
    }
    case 1:
    {
        unsigned int id;
        printf("Enter the entity id to delete it: ");
        scanf(" %u", &id);
        FILE *output = fopen("tema.bdb", "wb");
        Repairshop aux;
        int count = 0;
        while (fread(&aux, sizeof(Repairshop), 1, file))
        {
            if (aux.id == id)
            {
                counter--;
            }
            else
            {
                aux.id = count;
                fwrite(&aux, sizeof(Repairshop), 1, output);
                count++;
            }
            counter++;
        }
        remove(argv[1]);
        rename("tema.bdb", argv[1]);
        break;
    }
    case 2:
    {

        unsigned long long IMEI;
        printf("Enter the IMEI: ");
        scanf(" %llu", &IMEI);
        Repairshop aux;

        while (fread(&aux, sizeof(Repairshop), 1, file))
        {
            if (aux.IMEI == IMEI)
            {
                printf("%d | %s | %llu | %f | %f | %f | %f | %f | %u\n", aux.id, aux.repair_type, aux.IMEI, aux.price, aux.investment, aux.profit, aux.total_profit, aux.total_influx, aux.marked);
            }
        }
        break;
    }
    case 3:
    {
        unsigned long long IMEI;
        unsigned mark;
        printf("Enter the IMEI of the phone: ");
        scanf(" %llu", &IMEI);

        printf("  How is the phone mark or unmark? 0/1: ");
        scanf("%u", &mark);

        FILE *output = fopen("tema.bdb", "wb");
        Repairshop aux;

        while (fread(&aux, sizeof(Repairshop), 1, file))
        {
            if (aux.IMEI == IMEI && aux.marked != mark)
            {
                aux.marked = mark;
            }

            fwrite(&aux, sizeof(entity), 1, output);
        }

        remove(argv[1]);
        rename("tema.bdb", argv[1]);
        break;
    }
    }
    return 0;
}