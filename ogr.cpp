#include "gdal/ogrsf_frmts.h"

int main()

{
    /// Register all OGR drivers
    OGRRegisterAll();
    printf("register complete\n");

    /// Get PostgreSQL driver throught Singleton Manager of OGRSFDriverRegistrar.
    const char *pszDriverName = "PostgreSQL";
    OGRSFDriver *poDriver;
    poDriver = OGRSFDriverRegistrar::GetRegistrar()->GetDriverByName(pszDriverName);
    if(NULL == poDriver)
    {
        printf("Can not get driver \n");
    }
    else
    {
        printf("Get Driver succeesfully\n");
    }

    /// Open PostgreSQL database and establish connection.
    OGRDataSource *poDS;
    const char *pszConnInfo = "PG: host='192.168.1.99' port='5432' user='postgres' password='postgres' dbname='opengeo'";
    poDS = poDriver->Open(pszConnInfo);
    if(NULL == poDS)
    {
        printf("Can not connect to database\n");
    }
    else
    {
        printf("Connection established\n");
    }

    /// Get Layer from DataSource.
    OGRLayer  *poLayer;
    //poLayer = poDS->GetLayerByName( "waterply_900913" );
    const char *pszSQLCommand = "SELECT * \
                                  FROM waterply_900913 \
                                  WHERE ST_Contains( ST_MakeEnvelope(-8584936,4691869,-8561767,4710000),geom );";
    poLayer = poDS->ExecuteSQL(pszSQLCommand, NULL, NULL);
    if(NULL == poLayer)
    {
        printf("Get no Result Layers failed\n");
    }
    else
    {
        printf("Get Result Layer succussful\n");
    }

    /// Set Query statement here in OGRResultLayer.

    /// Get Layer metadata.
    OGRFeatureDefn *poFDefn = poLayer->GetLayerDefn();
    if(NULL != poFDefn)
    {
        printf("Get Layer Feature definition successfully\n");
    }

    /// Get Feature from Layer.
    OGRFeature *poFeature;
    poLayer->ResetReading();
    while( (poFeature = poLayer->GetNextFeature()) != NULL )
    {
        /// Get Attribute fields.
        int iField;
        int iFieldAmount = poFDefn->GetFieldCount();
        for( iField = 0; iField < iFieldAmount; iField++ )
        {
            OGRFieldDefn *poFieldDefn = poFDefn->GetFieldDefn( iField );

            if( poFieldDefn->GetType() == OFTInteger )
                printf( "%d,", poFeature->GetFieldAsInteger( iField ) );
            else if( poFieldDefn->GetType() == OFTReal )
                printf( "%.3f,", poFeature->GetFieldAsDouble(iField) );
            else if( poFieldDefn->GetType() == OFTString )
                printf( "%s,", poFeature->GetFieldAsString(iField) );
            else
                printf( "%s,", poFeature->GetFieldAsString(iField) );
        }

        /// Get Geometry of Feature.
        OGRGeometry *poGeometry;
        poGeometry = poFeature->GetGeometryRef();
        if( poGeometry != NULL 
                && wkbFlatten(poGeometry->getGeometryType()) == wkbPoint )
        {
            OGRPoint *poPoint = (OGRPoint *) poGeometry;

            printf( "%.3f,%3.f\n", poPoint->getX(), poPoint->getY() );
        }
        else
        {
            printf( "no point geometry\n" );
        }
        OGRFeature::DestroyFeature( poFeature );
    }

    //GDALClose( poDS );
}
