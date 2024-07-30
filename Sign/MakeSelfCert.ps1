$params = @{
    CertStoreLocation = 'Cert:\CurrentUser\My'
    DnsName = 'MyTestEnclaveCert'
    KeyUsage = 'DigitalSignature'
    KeyLength = 2048
    KeyAlgorithm = 'RSA'
    HashAlgorithm = 'SHA256'
    TextExtension = @(
        '2.5.29.37={text}1.3.6.1.5.5.7.3.3,1.3.6.1.4.1.311.76.57.1.15,1.3.6.1.4.1.311.97.814040577.346743379.4783502.105532346' )
}
New-SelfSignedCertificate @params