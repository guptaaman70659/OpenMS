// --------------------------------------------------------------------------
//                   OpenMS -- Open-Source Mass Spectrometry
// --------------------------------------------------------------------------
// Copyright The OpenMS Team -- Eberhard Karls University Tuebingen,
// ETH Zurich, and Freie Universitaet Berlin 2002-2012.
//
// This software is released under a three-clause BSD license:
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of any author or any participating institution
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission.
// For a full list of authors, refer to the file AUTHORS.
// --------------------------------------------------------------------------
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL ANY OF THE AUTHORS OR THE CONTRIBUTING
// INSTITUTIONS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// --------------------------------------------------------------------------
// $Maintainer: Mathias Walzer $
// $Authors: Mathias Walzer $
// --------------------------------------------------------------------------

#ifndef OPENMS_FORMAT_QCMLFILE_H
#define OPENMS_FORMAT_QCMLFILE_H

#include <OpenMS/CONCEPT/ProgressLogger.h>
#include <OpenMS/FORMAT/HANDLERS/XMLHandler.h>
#include <OpenMS/FORMAT/XMLFile.h>
#include <OpenMS/CONCEPT/UniqueIdGenerator.h>

#include <vector>
#include <map>
#include <set>
#include <algorithm>

namespace OpenMS
{
  /**
      @brief File adapter for QcML files

      This Class is supposed to internally collect the data for the qcML File

      @todo add FileHandler and XMLFile inheritance as soon as we are facing a more complicated cv and schema structure

      @ingroup FileIO
  */
  class OPENMS_DLLAPI QcMLFile :
    public Internal::XMLHandler,
    public Internal::XMLFile,
    public ProgressLogger
  {
public:
    /// Representation of a quality parameter
    struct OPENMS_DLLAPI QualityParameter
    {
      String name; ///< Name
      String id; ///< Identifier
      String value; ///< Value
      String cvRef; ///< cv reference
      String cvAcc; ///< cv accession
      String unitRef; ///< cv reference of the unit
      String unitAcc; ///< cv accession of the unit
      std::vector<String> colTypes; ///< type of the cols if QP has a table of values
      std::vector< std::vector<String> > tableRows; ///< cell values if QP has a table, type see colType
      //~ TODO -schema- coltypes with full definition (uintRef, unitAcc)

      ///Default constructor
      QualityParameter();

      QualityParameter(const QualityParameter& rhs);

      QualityParameter& operator=(const QualityParameter& rhs);

      String toXMLString(UInt indentation_level) const;
      String toCSVString(String separator) const;
    };

    /// Representation of an attachment
    struct OPENMS_DLLAPI Attachment
    {
      String name; ///< Name
      String value; ///< Value
      String cvRef; ///< cv reference
      String cvAcc; ///< cv accession
      String unitRef; ///< cv reference of the unit
      String unitAcc; ///< cv accession of the unit
      String binary; ///< binary content of the attachment
      String qualityRef; ///< reference to qp to which attachment, if empty attached to run/set

      ///Default constructor
      Attachment();

      Attachment(const Attachment& rhs);

      Attachment& operator=(const Attachment& rhs);

      String toXMLString(UInt indentation_level) const;
    };

    ///Default constructor
    QcMLFile();
    ///Destructor
    ~QcMLFile();

    ///Just adds a qualityparameter to run/set by the name r
    void addQualityParameter(String r, QualityParameter qp);
    ///Just adds a attachment to run/set by the name r
    void addAttachment(String r, Attachment at);
    ///Just removes qualityparameter by the name qp from run/set by the name r
    void removeQualityParameter(String r, String qp);
    ///Returns a String of a tab separated rows if found empty string else from run/set by the name filename of the qualityparameter by the name qpname
    String exportQualityParameter(const String filename, const String qpname) const;
    ///Returns the id of the parameter if found empty string else from run/set by the name filename
    String existsQualityParameter(const String filename, const String qpname) const;
    ///Store the QCFile
    void store(const String & filename) const;
    ///Load a QCFile
    void load(const String & filename);

    //~ int siz; //debug

protected:
    // Docu in base class
    virtual void endElement(const XMLCh * const /*uri*/, const XMLCh * const /*local_name*/, const XMLCh * const qname);

    // Docu in base class
    virtual void startElement(const XMLCh * const /*uri*/, const XMLCh * const /*local_name*/, const XMLCh * const qname, const xercesc::Attributes & attributes);

    // Docu in base class
    virtual void characters(const XMLCh * const chars, const XMLSize_t length);

    std::map<String, std::vector< QualityParameter > > runQualitysQPs_; //TODO run name attribute to schema of RunQuality
    std::map<String, std::vector< Attachment > > runQualitysAts_;
    //~ TODO setQuality

    String tag_;

    UInt progress_;
    QualityParameter qp_;
    Attachment at_;
    std::vector<String> row_;
    std::vector<String> header_;
    String name_;
    std::vector<QualityParameter> qps_;
    std::vector<Attachment> ats_;

  };

} // namespace OpenMS

#endif // OPENMS_FORMAT_QCMLFILE_H