# postgis 2.2/raster

directory hirerarchy **tree -FL 1**

```
.
├── CREDITS
├── DEBUG
├── doc/
├── install-sh*
├── loader/
├── macros/
├── Makefile.in
├── NEWS
├── raster_config.h.in
├── rt_core/
├── rt_pg/
├── scripts/
├── test/
├── TODO
└── Version.config

7 directories, 8 files
```

directory hierarchy **tree -FL 2**
```
.
├── CREDITS (project information)
├── DEBUG (PostGIS debugging information)
├── doc/ (doxygen folder)
│   ├── doxygen.cfg.in
│   ├── RFC1-SerializedFormat
│   └── RFC2-WellKnownBinaryFormat
├── install-sh* (shell script,function don't kown currently)
├── loader/ (raster2pgsql .c&.h file)
│   ├── Makefile.in
│   ├── raster2pgsql.c
│   └── raster2pgsql.h
├── macros/ (include a single file - ac_proj4_version.m4)
│   └── ac_proj4_version.m4
├── Makefile.in (configure read Makefile.in to generate Makefile)
├── NEWS (patches updated history news,patches traced information)
├── raster_config.h.in (multiple #undef stuff)
├── rt_core/
│   ├── librtcore.h
│   ├── librtcore_internal.h
│   ├── Makefile.in
│   ├── rt_band.c
│   ├── rt_context.c
│   ├── rt_geometry.c
│   ├── rt_mapalgebra.c
│   ├── rt_pixel.c
│   ├── rt_raster.c
│   ├── rt_serialize.c
│   ├── rt_serialize.h
│   ├── rt_spatial_relationship.c
│   ├── rt_statistics.c
│   ├── rt_util.c
│   ├── rt_warp.c
│   ├── rt_wkb.c
│   └── tags
├── rt_pg/
│   ├── Makefile.in
│   ├── Makefile.pgxs
│   ├── rtpg_band_properties.c
│   ├── rtpg_create.c
│   ├── rtpg_gdal.c
│   ├── rtpg_geometry.c
│   ├── rtpg_inout.c
│   ├── rtpg_internal.c
│   ├── rtpg_internal.h
│   ├── rtpg_mapalgebra.c
│   ├── rtpg_pixel.c
│   ├── rtpg_raster_properties.c
│   ├── rtpg_spatial_relationship.c
│   ├── rtpg_statistics.c
│   ├── rtpg_utility.c
│   ├── rtpostgis.c
│   ├── rtpostgis_drop.sql.in
│   ├── rtpostgis.h
│   ├── rtpostgis_legacy.sql.in
│   ├── rtpostgis.sql.in
│   └── rtpostgis_upgrade_cleanup.sql.in
├── scripts/(experimental pl/pgSQL functions to be implemented later)
│   ├── Makefile.in
│   ├── plpgsql/
│   └── python/
├── test/
│   ├── cunit/
│   ├── Makefile.in
│   └── regress/
├── TODO (TODO items list for PostGIS Raster)
└── Version.config (Version numbering central repository)

11 directories, 55 files
```

