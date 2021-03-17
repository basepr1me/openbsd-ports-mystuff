# $OpenBSD$

COMMENT =	todo

MODGO_MODNAME =	github.com/micromdm/micromdm
MODGO_VERSION =	v1.8.0

DISTNAME =	micromdm-${MODGO_VERSION}
PKGNAME =	micromdm-1.8.0

CATEGORIES =	sysutils

# MIT
PERMIT_PACKAGE =	Yes

WANTLIB += c pthread

MODULES =		lang/go

MODGO_MODULES =	\
	github.com/!robots!and!pencils/buford	 v0.12.0 \
	github.com/boltdb/bolt			 v1.3.1 \
	github.com/davecgh/go-spew		 v1.1.1 \
	github.com/fullsailor/pkcs7		 v0.0.0-20190404230743-d7302db945fa \
	github.com/garyburd/go-oauth		 v0.0.0-20180319155456-bca2e7f09a17 \
	github.com/go-kit/kit			 v0.7.0 \
	github.com/go-logfmt/logfmt		 v0.3.0 \
	github.com/go-sql-driver/mysql		 v1.4.0 \
	github.com/go-stack/stack		 v1.7.0 \
	github.com/gogo/protobuf		 v1.3.1 \
	github.com/golang/protobuf		 v1.4.2 \
	github.com/google/go-cmp		 v0.4.0 \
	github.com/google/uuid			 v1.1.1 \
	github.com/gorilla/context		 v1.1.1 \
	github.com/gorilla/mux			 v1.6.2 \
	github.com/groob/finalizer		 v0.0.0-20170707115354-4c2ed49aabda \
	github.com/groob/pkcs7			 v0.0.0-20180824154052-36585635cb64 \
	github.com/groob/plist			 v0.0.0-20180203051248-dd56909aee38 \
	github.com/jmoiron/sqlx			 v0.0.0-20180614180643-0dae4fefe7c0 \
	github.com/kisielk/errcheck		 v1.2.0 \
	github.com/kisielk/gotool		 v1.0.0 \
	github.com/kolide/kit			 v0.0.0-20180912215818-0c28f72eb2b0 \
	github.com/kr/logfmt			 v0.0.0-20140226030751-b84e30acd515 \
	github.com/lann/builder			 v0.0.0-20180802200727-47ae307949d0 \
	github.com/lann/ps			 v0.0.0-20150810152359-62de8c46ede0 \
	github.com/lib/pq			 v1.0.0 \
	github.com/mattn/go-sqlite3		 v1.9.0 \
	github.com/micromdm/go4			 v0.0.0-20210104222236-8a0936d9e451 \
	github.com/micromdm/scep		 v1.0.1-0.20181014170139-9be65e185499 \
	github.com/pkg/errors			 v0.8.0 \
	github.com/pmezard/go-difflib		 v1.0.0 \
	github.com/pressly/goose		 v2.3.0+incompatible \
	github.com/stretchr/testify		 v1.2.2 \
	github.com/ziutek/mymysql		 v1.5.4 \
	golang.org/x/crypto			 v0.0.0-20200622213623-75b288015ac9 \
	golang.org/x/net			 v0.0.0-20190404232315-eb5bcb51f2a3 \
	golang.org/x/sys			 v0.0.0-20190412213103-97732733099d \
	golang.org/x/text			 v0.3.0 \
	golang.org/x/tools			 v0.0.0-20181030221726-6c7e314b6563 \
	golang.org/x/xerrors			 v0.0.0-20191204190536-9bdfabe68543 \
	google.golang.org/appengine		 v1.2.0 \
	google.golang.org/protobuf		 v1.23.0 \
	gopkg.in/!masterminds/squirrel.v1	 v1.0.0-20170825200431-a6b93000bd21
MODGO_MODFILES =	\
	github.com/fullsailor/pkcs7	 v0.0.0-20190404230743-d7302db945fa \
	github.com/go-kit/kit		 v0.4.0 \
	github.com/go-kit/kit		 v0.5.0 \
	github.com/go-stack/stack	 v1.6.0 \
	github.com/golang/protobuf	 v1.2.0 \
	github.com/golang/protobuf	 v1.4.0 \
	github.com/golang/protobuf	 v1.4.0-rc.1 \
	github.com/golang/protobuf	 v1.4.0-rc.1.0.20200221234624-67d41d38c208 \
	github.com/golang/protobuf	 v1.4.0-rc.2 \
	github.com/golang/protobuf	 v1.4.0-rc.4.0.20200313231945-b860323f09d0 \
	github.com/google/go-cmp	 v0.3.0 \
	github.com/google/go-cmp	 v0.3.1 \
	github.com/gorilla/context	 v0.0.0-20160226214623-1ea25387ff6f \
	github.com/gorilla/mux		 v1.4.0 \
	golang.org/x/crypto		 v0.0.0-20190308221718-c2843e01d9a2 \
	golang.org/x/net		 v0.0.0-20170726083632-f5079bd7f6f7 \
	golang.org/x/net		 v0.0.0-20180724234803-3673e40ba225 \
	golang.org/x/sys		 v0.0.0-20170728174421-0f826bdd13b5 \
	golang.org/x/sys		 v0.0.0-20190215142949-d0b11bdaac8a \
	google.golang.org/protobuf	 v0.0.0-20200109180630-ec00e32a8dfd \
	google.golang.org/protobuf	 v0.0.0-20200221191635-4d8936d0db64 \
	google.golang.org/protobuf	 v0.0.0-20200228230310-ab0ca4ff8a60 \
	google.golang.org/protobuf	 v1.20.1-0.20200309200217-e05f789c0967 \
	google.golang.org/protobuf	 v1.21.0

.include <bsd.port.mk>
