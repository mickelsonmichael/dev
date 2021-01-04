# SmtpClient

At LMCU, we discussed whether or not we are going to use the `SmtpClient` provided by Microsoft going forward. 

This discussion all started with Leighann noticing that the [official Documentation for the SmtpClient](https://docs.microsoft.com/en-us/dotnet/api/system.net.mail.smtpclient?view=netframework-4.8) mentions the fact that the `SmtpClient` class is not considered Obsolete and that instead it is recommended to use an external third party like [MailKit](https://github.com/jstedfast/MailKit).

However, it would seem that the Obsolete was an issue with some automatic documentation. [See this Github issue](https://github.com/dotnet/dotnet-api-docs/issues/2986). Essentially the class is deprecated in Xamarin/Mono but not deprecated in other version of .NET.

This issue on GitHub has caused a lot of confusion, both for me and for the community at large. Lots of people interpret it as just a bug while others interpret it as an intended obsolescence that just appears to be a bug.

About halfway down the issue, one of the maintainers gives this official stance

>BTW: SmtpClient is obsolete API: https://github.com/dotnet/platform-compat/blob/master/docs/DE0005.md (that is what causes the warning DE0005.
We do not plan to add the Obsolete attribute on it to avoid breaking everyone's compilation (with warnings treated as errors).

There was also a later [Pull Request](https://github.com/dotnet/dotnet-api-docs/pull/3320#pullrequestreview-300222752) that illuminated the issue a little bit more clearly

> … it might be best to also add a note box with something like the following:
> The SmtpClient class is obsolete in Xamarin. However,
>
> - It is included in the .NET Standard and therefore must part part of any .NET implementation
> - It is present and can be used in .NET Framework 4 through .NET Framework 4.8.  
> - It is usable in .NET Core, but its use is not recommended.
