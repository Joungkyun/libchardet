%define revisions "$Id$"
%define _unpackaged_files_terminate_build 0

Summary: Mozilla Universal Chardet library
Summary(ko): 모질라 유니버샬 캐릭터셋 디텍트 라이브러리
Name: libchardet
Version: 1.0.4
Release: 1
Epoch: 1
License: MPL
Group: System Environment/Libraries
Source0: http://mirror.oops.org/pub/oops/%{name}/%{name}-%{version}.tar.bz2
URL: http://oops.org
BuildRequires: libstdc++-devel
Requires: libstdc++

Buildroot: /var/tmp/%{name}-%{version}-root

%description
libchardet provides an interface to Mozilla's universal charset detector,
which detects the charset used to encode data.

%package devel
Summary: Header and object files for development using libchardet
Summary(ko): libchardet 를 이용하여 개발하기 위한 header 파일과 목적 파일들
Group: System Environment/Libraries
Requires: %{name} = %{epoch}:%{version}-%{release}, libstdc++-devel

%description devel
The libchardet-devel package contains the header and object files necessary
for developing programs which use the libchardet libraries.

%prep
[ "%{buildroot}" != "/" ] && %{__rm} -rf %{buildroot}
%setup -q

%build
%configure

%{__make} %{?_smp_mflags}

%install
%{__make} DESTDIR=%{buildroot} install

%clean
%{__rm} -rf %{buildroot}

%post
/sbin/ldconfig

%postun
/sbin/ldconfig

%files
%defattr(0755,root,root)
%{_libdir}/%{name}.so.*

%files devel
%defattr(0644,root,root,0755)
%attr(0755,root,root) %{_bindir}/chardet-config
%{_libdir}/*.so
%{_libdir}/*.a
%{_libdir}/*.la
%{_libdir}/pkgconfig/chardet.pc
%{_includedir}/chardet/*.h
%{_mandir}/man3/*
%{_mandir}/ko/man3/*

%changelog
* Fri Feb 14 2014 JoungKyun.Kim <http://oops.org> 1:1.0.4-1
- packaged 1.0.4
