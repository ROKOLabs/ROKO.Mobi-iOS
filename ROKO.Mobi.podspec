Pod::Spec.new do |s|
  s.name             = "ROKO.Mobi"
  s.version          = "1.12.3.1"
  s.license          = 'MPL'
  s.homepage         = "https://github.com/ROKOLabs/ROKO.Mobi.iOS"
  s.author           = "ROKO Labs"
  s.summary          = "ROKO.Mobi iOS SDK"
  s.description      = <<-DESC
The ROKO.Mobi SDK provides a means for taking photos, dressing them up in stickers, and sharing the results with the world through FB, Twitter, e-mail, or sms.
                       DESC

  s.source           = { :git => "https://github.com/ROKOLabs/ROKO.Mobi.iOS.git", :tag => s.version.to_s }
  s.social_media_url = 'https://roko.mobi'
  s.platform         = :ios, '8.0'
  s.requires_arc     = true
  s.vendored_frameworks = 'Framework/ROKOMobi.framework'
  s.resource            = 'Framework/ROKOMobi.framework/ROKOMobiResources.bundle'
  s.xcconfig = {
    :"OTHER_LDFLAGS" => "$(inherited) -ObjC"
  }
end
