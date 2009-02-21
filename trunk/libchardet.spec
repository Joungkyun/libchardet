%define revisions "$Id: libchardet.spec,v 1.1.1.1 2009-02-21 20:08:02 oops Exp $"
%define _unpackaged_files_terminate_build 0

Summary: Mozilla Universal Chardet library
Summary(ko): ������ ���Ϲ��� ĳ���ͼ� ����Ʈ ���̺귯��
Name: libchardet
Version: 0.0.1
Release: 1
Epoch: 1
License: MPL
Group: System Environment/Libraries
Source0: ftp://mirror.oops.org/pub/oops/%{name}/%{name}-%{version}.tar.bz2
URL: http://devel.oops.org
BuildRequires: libstdc++-devel
Requires: libstdc++

Buildroot: /var/tmp/%{name}-%{version}-root

%description
libchardet provides an interface to Mozilla's universal charset detector,
which detects the charset used to encode data.

%package devel
Summary: Header and object files for development using libchardet
Summary(ko): libchardet �� �̿��Ͽ� �����ϱ� ���� header ���ϰ� ���� ���ϵ�
Group: System Environment/Libraries
Requires: %{name} libstdc++-devel

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
%{_includedir}/chardet/*.h

%changelog
* Fri Feb 22 2008 JoungKyun.Kim <http://oops.org> 1:1.0.0-1
- first packing

