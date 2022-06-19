# quick-lint-js overlay for FreeBSD Ports

## Installation

1. Make sure you have a ports tree checked out under `/usr/ports`.
   1. If not:
   ```console
   # zfs destroy -r zroot/usr/ports
   # zfs create -omountpoint=/usr/ports zroot/usr/ports
   # git clone ssh://anongit@git.freebsd.org/ports.git /usr/ports
   ```

2. Build the port
   ```console
   $ cd devel/quick-lint-js
   $ make config
   $ make
   # make install
   ```

## Notes

- Test the port with poudriere:

		poudriere testport -j 130p4amd64 -O qljs_overlay -p main -kc devel/quick-lint-js
