# 1 - Information and Network Security Concepts

## 1.1 - Cybersecurity, Information Security, and Network Security

**Cybersecurity** is the protection of information that is stored, transmitted, and processed in a networked system of computers, other digital devices, and network devices and transmission lines, including the Internet. Protection encompasses confidentiality, integrity, availability, authenticity, and accountability. Methods of protection include organizational policies and procedures, as well as technical means such as encryption and secure communications protocols.

The following are subsets of cybersecurity:

- **Information security** refers to preservation of confidentiality, integrity, and availability of information. In addition, other properties, such as authenticity, accountability, nonrepudiation, and reliability can also be involved.

- **Network Security** refers to protection of networks and their service from unauthorized modification, destruction, or disclosure, and provision of assurance that the network performs its critical functions correctly and there are no harmful side effects.

### Security Objectives

The **CIA Triad** lies at the heart of information and network security:

1. **Confidentiality** spans two related concepts:
    - **Data confidentiality** assures that private or confidential information is not made available or disclosed to unauthorized individuals.
    - **Privacy** assures that individuals control or influence what information related to them may be collected and stored and by whom that information may be disclosed.
2. **Integrity** spans two related concepts:
    - **Data integrity** assures that data and programs are changed only in a specific and authorized manner. This encompasses **data authenticity**, which means that a digital object is indeed what it claimed to be, and **nonrepudiation**, which is assurance that the sender of information is provided with proof of delivery and the recipient is provided with proof of the sender's identity.
    - **System integrity** assures that a system performs its intended function in an unimpaired manner, free from deliberate or inadvertent unauthorized manipulation of the system.
3. **Availability** assures that systems work promptly and service is not denied to authorized users.

Some in the security field feel that the following concepts should also be added:

4. **Authenticity** is the property of being genuine and being able to be verified and trusted with confidence in the validity of a transmission, a message, or message originator. This means verifying that users are who they say they are and that each input arriving at the system came from a trusted source.
5. **Accountability** is the requirement that actions of an entity to be traced uniquely back to that entity. This allows security breaches to be traced back to the responsible party.

## 1.2 - The OSI Security Architecture

The **open systems interconnection (OSI)** defines a systematic approach to providing security in a system. This abstract view allows us to gain a broad understanding of the concepts of cybersecurity. The OSI security architecture focuses on security attacks, mechanisms, and services:

- **Security attacks** are actions that compromise the security of information owned by an organization
- **Security mechanisms** are processes that are designed to detect, prevent, or recover from a security attack
- **Security services** are processing and communication services that enhance the security of the data processing systems and the information transfers of an organization. The services are intended to counter security attacks, and they make use of one or more security mechanisms to provide the service.

The following terms are often used when discussing cybersecurity:

- **Threat**: Any circumstance or event with the potential to adversely impact organization operations (including mission, functions, image, or reputation), organizational assets, individuals, other organizations, or the Nation through an information system via unauthorized access, destruction, disclosure, modification of information, and/or denial of service.
- **Attack**: Any kind of malicious activity with that attempts to collect, disrupt, deny, degrade, or destroy information system resources or the information itself.

## 1.3 - Security Attacks

### Passive Attacks

**Passive attacks** are in the nature of eavesdropping on transmissions. Two types of passive attacks are as follows:

- **Release of message contents** involves the unauthorized disclosure of information.
- **Traffic analysis** allows adversaries to observe patterns in information traffic.

Passive attacks are generally more difficult to detect. As such, the emphasis on preventing passive attacks is on prevention.

### Active Attacks

**Active attacks** involve some modification of the data stream or the creation of a false stream and can be divided into four categories:

1. A **masquerade** takes place when one entity pretends to be another entity.
2. **Replay** involves the passive capture of a data unit and its subsequent retransmission to produce an unauthorized effect.
3. **Data modification** occurs when some portion of a legitimate message is altered.
4. The **denial of service** prevents or inhibits the normal use or management of communication facilities.

Active attacks are generally easier to detect but harder to prevent (prevention would require physical protection for all communication facilities and paths at all times).

## 1.4 - Security Services


