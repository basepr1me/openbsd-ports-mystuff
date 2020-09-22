# $OpenBSD: $

COMMENT =	software soundcard for AX.25 packets

V =		1.5
DISTNAME =	direwolf-${V}

GH_ACCOUNT =	wb2osz
GH_PROJECT =	direwolf
GH_TAGNAME =	${V}

CATEGORIES =	comms

HOMEPAGE =	https://packet-radio.net/direwolf/

MAINTAINER =	Tracey Emery <tracey@openbsd.org>

#LGPLv2
PERMIT_PACKAGE =	Yes

WANTLIB += c m ossaudio pthread

FAKE_FLAGS =	PREFIX="${PREFIX}"

RUN_DEPENDS =	devel/desktop-file-utils

USE_GMAKE =		Yes

NO_TEST =		Yes

post-patch:
	${SUBST_CMD} ${WRKDIST}/Makefile.linux

post-install:

	${INSTALL_PROGRAM} ${WRKDIST}/direwolf ${PREFIX}/bin/direwolf
	${INSTALL_PROGRAM} ${WRKDIST}/decode_aprs ${PREFIX}/bin/decode_aprs
	${INSTALL_PROGRAM} ${WRKDIST}/text2tt ${PREFIX}/bin/text2tt
	${INSTALL_PROGRAM} ${WRKDIST}/tt2text ${PREFIX}/bin/tt2text
	${INSTALL_PROGRAM} ${WRKDIST}/ll2utm ${PREFIX}/bin/ll2utm
	${INSTALL_PROGRAM} ${WRKDIST}/utm2ll ${PREFIX}/bin/utm2ll
	${INSTALL_PROGRAM} ${WRKDIST}/aclients ${PREFIX}/bin/aclients
	${INSTALL_PROGRAM} ${WRKDIST}/log2gpx ${PREFIX}/bin/log2gpx
	${INSTALL_PROGRAM} ${WRKDIST}/gen_packets ${PREFIX}/bin/gen_packets
	${INSTALL_PROGRAM} ${WRKDIST}/atest ${PREFIX}/bin/atest
	${INSTALL_PROGRAM} ${WRKDIST}/ttcalc ${PREFIX}/bin/ttcalc
	${INSTALL_PROGRAM} ${WRKDIST}/kissutil ${PREFIX}/bin/kissutil
	${INSTALL_PROGRAM} ${WRKDIST}/cm108 ${PREFIX}/bin/cm108
	${INSTALL_PROGRAM} ${WRKDIST}/dwespeak.sh ${PREFIX}/bin/dwspeak.sh

	${INSTALL_SCRIPT} ${WRKDIST}/telemetry-toolkit/telem-balloon.pl \
	    ${PREFIX}/bin/telem-balloon.pl
	${INSTALL_SCRIPT} ${WRKDIST}/telemetry-toolkit/telem-bits.pl \
	    ${PREFIX}/bin/telem-bits.pl
	${INSTALL_SCRIPT} ${WRKDIST}/telemetry-toolkit/telem-data.pl \
	    ${PREFIX}/bin/telem-data.pl
	${INSTALL_SCRIPT} ${WRKDIST}/telemetry-toolkit/telem-data91.pl \
	    ${PREFIX}/bin/telem-data91.pl
	${INSTALL_SCRIPT} ${WRKDIST}/telemetry-toolkit/telem-eqns.pl \
	    ${PREFIX}/bin/telem-eqns.pl
	${INSTALL_SCRIPT} ${WRKDIST}/telemetry-toolkit/telem-parm.pl \
	    ${PREFIX}/bin/telem-parm.pl
	${INSTALL_SCRIPT} ${WRKDIST}/telemetry-toolkit/telem-seq.sh \
	    ${PREFIX}/bin/telem-seq.sh
	${INSTALL_SCRIPT} ${WRKDIST}/telemetry-toolkit/telem-unit.pl \
	    ${PREFIX}/bin/telem-unit.pl
	${INSTALL_SCRIPT} ${WRKDIST}/telemetry-toolkit/telem-volts.py \
	    ${PREFIX}/bin/telem-volts.py

	${INSTALL_DATA_DIR} ${PREFIX}/share/direwolf/
	${INSTALL_DATA} ${WRKDIST}/tocalls.txt \
	    ${PREFIX}/share/direwolf/tocalls.txt
	${INSTALL_DATA} ${WRKDIST}/symbols-new.txt \
	    ${PREFIX}/share/direwolf/symbols-new.txt
	${INSTALL_DATA} ${WRKDIST}/symbolsX.txt \
	    ${PREFIX}/share/direwolf/symbolsX.txt

	${INSTALL_DATA_DIR} ${PREFIX}/share/direwolf/pixmaps/
	${INSTALL_DATA_DIR} ${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKDIST}/dw-icon.png \
	    ${PREFIX}/share/direwolf/pixmaps/dw-icon.png
	${INSTALL_DATA} ${WRKDIST}/direwolf.desktop \
	    ${PREFIX}/share/applications/direwolf.desktop

	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/direwolf/
	${INSTALL_DATA} ${WRKDIST}/CHANGES.md \
	    ${PREFIX}/share/doc/direwolf/CHANGES.md
	${INSTALL_DATA} ${WRKDIST}/LICENSE-dire-wolf.txt \
	    ${PREFIX}/share/doc/direwolf/LICENSE-dire-wolf.txt
	${INSTALL_DATA} ${WRKDIST}/LICENSE-other.txt \
	    ${PREFIX}/share/doc/direwolf/LICENSE-other.txt

	${INSTALL_DATA} ${WRKDIST}/doc/README.md \
	    ${PREFIX}/share/doc/direwolf/README.md
	${INSTALL_DATA} ${WRKDIST}/doc/2400-4800-PSK-for-APRS-Packet-Radio.pdf \
	    ${PREFIX}/share/doc/direwolf/2400-4800-PSK-for-APRS-Packet-Radio.pdf
	${INSTALL_DATA} \
	    ${WRKDIST}/doc/A-Better-APRS-Packet-Demodulator-Part-1-1200-baud.pdf \
	    ${PREFIX}/share/doc/direwolf/A-Better-APRS-Packet-Demodulator-Part-1-1200-baud.pdf
	${INSTALL_DATA} \
	    ${WRKDIST}/doc/A-Better-APRS-Packet-Demodulator-Part-2-9600-baud.pdf \
	    ${PREFIX}/share/doc/direwolf/A-Better-APRS-Packet-Demodulator-Part-2-9600-baud.pdf
	${INSTALL_DATA} \
	    ${WRKDIST}/doc/A-Closer-Look-at-the-WA8LMF-TNC-Test-CD.pdf \
	    ${PREFIX}/share/doc/direwolf/A-Closer-Look-at-the-WA8LMF-TNC-Test-CD.pdf
	${INSTALL_DATA} \
	    ${WRKDIST}/doc/APRS-Telemetry-Toolkit.pdf \
	    ${PREFIX}/share/doc/direwolf/APRS-Telemetry-Toolkit.pdf
	${INSTALL_DATA} \
	    ${WRKDIST}/doc/APRStt-Implementation-Notes.pdf \
	    ${PREFIX}/share/doc/direwolf/APRStt-Implementation-Notes.pdf
	${INSTALL_DATA} \
	    ${WRKDIST}/doc/APRStt-interface-for-SARTrack.pdf \
	    ${PREFIX}/share/doc/direwolf/APRStt-interface-for-SARTrack.pdf
	${INSTALL_DATA} \
	    ${WRKDIST}/doc/APRStt-Listening-Example.pdf \
	    ${PREFIX}/share/doc/direwolf/APRStt-Listening-Example.pdf
	${INSTALL_DATA} \
	    ${WRKDIST}/doc/Bluetooth-KISS-TNC.pdf \
	    ${PREFIX}/share/doc/direwolf/Bluetooth-KISS-TNC.pdf
	${INSTALL_DATA} \
	    ${WRKDIST}/doc/Going-beyond-9600-baud.pdf \
	    ${PREFIX}/share/doc/direwolf/Going-beyond-9600-baud.pdf
	${INSTALL_DATA} \
	    ${WRKDIST}/doc/Raspberry-Pi-APRS.pdf \
	    ${PREFIX}/share/doc/direwolf/Raspberry-Pi-APRS.pdf
	${INSTALL_DATA} \
	    ${WRKDIST}/doc/Raspberry-Pi-APRS-Tracker.pdf \
	    ${PREFIX}/share/doc/direwolf/Raspberry-Pi-APRS-Tracker.pdf
	${INSTALL_DATA} \
	    ${WRKDIST}/doc/Raspberry-Pi-SDR-IGate.pdf \
	    ${PREFIX}/share/doc/direwolf/Raspberry-Pi-SDR-IGate.pdf
	${INSTALL_DATA} \
	    ${WRKDIST}/doc/Successful-APRS-IGate-Operation.pdf \
	    ${PREFIX}/share/doc/direwolf/Successful-APRS-IGate-Operation.pdf
	${INSTALL_DATA} \
	    ${WRKDIST}/doc/User-Guide.pdf \
	    ${PREFIX}/share/doc/direwolf/User-Guide.pdf
	${INSTALL_DATA} \
	    ${WRKDIST}/doc/WA8LMF-TNC-Test-CD-Results.pdf \
	    ${PREFIX}/share/doc/direwolf/WA8LMF-TNC-Test-CD-Results.pdf

	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/direwolf/examples/
	${INSTALL_DATA} ${WRKDIST}/direwolf.conf \
	    ${PREFIX}/share/doc/direwolf/examples/direwolf.conf
	${INSTALL_SCRIPT} ${WRKDIST}/dw-start.sh \
	    ${PREFIX}/share/doc/direwolf/examples/dw-start.sh
	${INSTALL_DATA} ${WRKDIST}/sdr.conf \
	    ${PREFIX}/share/doc/direwolf/examples/sdr.conf
	${INSTALL_DATA} ${WRKDIST}/telemetry-toolkit/telem-m0xer-3.txt \
	    ${PREFIX}/share/doc/direwolf/examples/telem-m0xer-3.txt
	${INSTALL_DATA} ${WRKDIST}/telemetry-toolkit/telem-balloon.conf \
	    ${PREFIX}/share/doc/direwolf/examples/telem-balloon.conf
	${INSTALL_DATA} ${WRKDIST}/telemetry-toolkit/telem-volts.conf \
	    ${PREFIX}/share/doc/direwolf/examples/telem-volts.conf

	${INSTALL_MAN} ${WRKDIST}/man1/aclients.1 \
	    ${PREFIX}/man/man1/aclients.1
	${INSTALL_MAN} ${WRKDIST}/man1/atest.1 \
	    ${PREFIX}/man/man1/atest.1
	${INSTALL_MAN} ${WRKDIST}/man1/decode_aprs.1 \
	    ${PREFIX}/man/man1/decode_aprs.1
	${INSTALL_MAN} ${WRKDIST}/man1/direwolf.1 \
	    ${PREFIX}/man/man1/direwolf.1
	${INSTALL_MAN} ${WRKDIST}/man1/gen_packets.1 \
	    ${PREFIX}/man/man1/gen_packets.1
	${INSTALL_MAN} ${WRKDIST}/man1/kissutil.1 \
	    ${PREFIX}/man/man1/kissutil.1
	${INSTALL_MAN} ${WRKDIST}/man1/ll2utm.1 \
	    ${PREFIX}/man/man1/ll2utm.1
	${INSTALL_MAN} ${WRKDIST}/man1/log2gpx.1 \
	    ${PREFIX}/man/man1/log2gpx.1
	${INSTALL_MAN} ${WRKDIST}/man1/text2tt.1 \
	    ${PREFIX}/man/man1/text2tt.1
	${INSTALL_MAN} ${WRKDIST}/man1/tt2text.1 \
	    ${PREFIX}/man/man1/tt2text.1
	${INSTALL_MAN} ${WRKDIST}/man1/utm2ll.1 \
	    ${PREFIX}/man/man1/utm2ll.1

	# ${INSTALL_DATA} ${WRKDIST}/99-direwolf-cmedia.rules \
	#     ${PREFIX}/etc/udev/rules.d/99-direwolf-cmedia.rules

.include <bsd.port.mk>
