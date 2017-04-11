//
//  STPPaymentConfiguration.h
//  Stripe
//
//  Created by Jack Flintermann on 5/18/16.
//  Copyright © 2016 Stripe, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "STPBackendAPIAdapter.h"
#import "STPPaymentMethod.h"
#import "STPPaymentMethodType.h"
#import "STPTheme.h"

NS_ASSUME_NONNULL_BEGIN

/**
 An `STPPaymentConfiguration` represents all the options you can set or change
 around a payment. 
 
 You provide an `STPPaymentConfiguration` object to your `STPPaymentContext` 
 when making a charge. The configuration generally has settings that
 will not change from payment to payment and thus is reusable, while the context 
 is specific to a single particular payment instance.
 */
@interface STPPaymentConfiguration : NSObject<NSCopying>

/**
 This is a convenience singleton configuration that uses the default values
 for every property
 */
+ (instancetype)sharedConfiguration;

/**
 *  Your Stripe publishable key. You can get this from https://dashboard.stripe.com/account/apikeys .
 */
@property (nonatomic, copy) NSString *publishableKey;

/**
 *  If YES, STPPaymentContext will generate STPSource objects when creating
 *  new cards. Otherwise it will generate STPCard objects.
 *
 *  The default value is NO
 *
 *  @see https://stripe.com/docs/sources
 */
@property (nonatomic) BOOL useSourcesForCards;

/**
 *  An array of payment method type objects that represents the list of
 *  the available payment methods available to users of your app.
 * 
 *  The methods in this list will be shown to users in STPPaymentMethodsViewController
 *  for users to choose from in the order they are listed in this array.
 *  Any methods types not in either this array will not be available to users 
 *  of your app.
 *
 *  If a method appears in the array twice, all but the first will be removed.
 */
@property (nonatomic, copy) NSArray<STPPaymentMethodType *> *availablePaymentMethodTypes;

/**
 *  The billing address fields the user must fill out when prompted for their 
 *  payment details. These fields will all be present on the returned token from 
 *  Stripe. See https://stripe.com/docs/api#create_card_token for more information.
 */
@property (nonatomic) STPBillingAddressFields requiredBillingAddressFields;

/**
 *  The billing address fields the user must fill out when prompted for their 
 *  shipping info.
 */
@property (nonatomic) PKAddressField requiredShippingAddressFields;

/**
 *  The type of shipping for this purchase. This property sets the labels 
 *  displayed when the user is prompted for shipping info, and whether they 
 *  should also be asked to select a shipping method.
 *
 *  The default value is STPShippingTypeShipping.
 */
@property (nonatomic) STPShippingType shippingType;

/**
 *  The name of your company, for displaying to the user during payment flows.
 *  For example, when using Apple Pay, the payment sheet's final line item will 
 *  read "PAY {companyName}". This defaults to the name of your iOS application.
 */
@property (nonatomic, copy) NSString *companyName;

/**
 *  The Apple Merchant Identifier to use during Apple Pay transactions.
 *  To create one of these, see our guide at https://stripe.com/docs/mobile/apple-pay. 
 *  You must set this to a valid identifier in order to automatically enable Apple Pay.
 */
@property (nonatomic, nullable, copy) NSString *appleMerchantIdentifier;

/**
 *  If you use payment methods which require redirect flows, this returnURL
 *  must be set to a URL that will bring the user back into your app so they
 *  can continue your checkout flow. It can be either a universal link or a 
 *  native scheme.
 *
 *  To learn more about universal links, see https://developer.apple.com/library/content/documentation/General/Conceptual/AppSearch/UniversalLinks.html
 *  To learn more about native url schemes, see https://developer.apple.com/library/content/documentation/iPhone/Conceptual/iPhoneOSProgrammingGuide/Inter-AppCommunication/Inter-AppCommunication.html#//apple_ref/doc/uid/TP40007072-CH6-SW10
 */
@property (nonatomic, nullable, copy) NSURL *returnURL  NS_EXTENSION_UNAVAILABLE("Redirect based sources are not available in extensions");

@end

NS_ASSUME_NONNULL_END
