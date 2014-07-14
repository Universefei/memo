#include "gdal/ogrsf_frmts.h"
//#include "gdal/gdal.h"
//#include "gdal/gdal_priv.h"

int main()

{
    /// Register all OGR drivers
    OGRRegisterAll();

    /// Get PostgreSQL driver throught Singleton Manager of OGRSFDriverRegistrar.
    const char *pszDriverName = "PG";
    OGRSFDriver *poDriver;
    poDriver = OGRSFDriverRegistrar::GetRegistrar()->GetDriverByName(pszDriverName);

    /// Open PostgreSQL database and establish connection.
    OGRDataSource *poDS;
    poDS = poDriver->Open("host=192.168.1.99 port=5432 user=postgres password=postgres dbname=opengeo");


    /// Get Layer from DataSource.
    OGRLayer  *poLayer;
    poLayer = poDS->GetLayerByName( "point" );

    /// Set Query statement here in OGRResultLayer.

    /// Get Feature from Layer.
    OGRFeature *poFeature;
    poLayer->ResetReading();
    while( (poFeature = poLayer->GetNextFeature()) != NULL )
    {
        /// Get Attribute fields.
        OGRFeatureDefn *poFDefn = poLayer->GetLayerDefn();
        int iField;

        for( iField = 0; iField < poFDefn->GetFieldCount(); iField++ )
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
