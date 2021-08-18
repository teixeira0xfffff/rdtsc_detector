# rdtsc_detector
rdtsc x86 instruction to detect virtual machines

# What is rdtsc?
The Time Stamp Counter (TSC) is a 64-bit register present on all x86 processors since the Pentium. It counts the number of cycles since reset. The instruction RDTSC returns the TSC in EDX:EAX. In x86-64 mode, RDTSC also clears the higher 32 bits of RAX and RDX. Its opcode is 0F 31.


Initially, this value was used to count the actual internal processor clock cycles. It was meant for developers to measure how many cycles a routine takes to complete. It was good to measure performance.

In the latest Intel processor families, this counter increases at a constant rate, which is determined by the maximum frequency the processor can run at that boot. Maximum does not mean current, as power-saving measures can dynamically change the velocity of the processor. This means it is not good to measure performance anymore, because the processor frequency can change at runtime and ruin the metric. On the other hand, now it can be used to measure time.

![system schema](https://i.imgur.com/BnNGJX8.png)

References:

[1] https://en.wikipedia.org/wiki/Time_Stamp_Counter

[2] https://randomascii.wordpress.com/2011/07/29/rdtsc-in-the-age-of-sandybridge/

[3] http://www.vmware.com/files/pdf/VMware_paravirtualization.pdf

[4] http://www.vmware.com/files/pdf/Timekeeping-In-VirtualMachines.pdf

[5] https://virtualblocks.wordpress.com/2010/06/22/cpu-ready-over-built-vm-or-over-utilized-host/

[6] http://www.spug.co.uk/?p=294